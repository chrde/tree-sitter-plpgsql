function kw(word, aliasAsWord = true) {
  let pattern = ""
  for (const letter of word) {
    pattern += `[${letter}${letter.toUpperCase()}]`
  }
  let result = new RegExp(pattern)
  if (aliasAsWord) {
    result = alias(result, word);
  }
  return result
}

function separated(separator, rule) {
  return optional(separated1(separator, rule));
}

function separated1(separator, rule) {
  return seq(rule, repeat(seq(separator, rule)));
}

function commaSep1(rule) {
  return separated1(",", rule);
}

function commaSep(rule) {
  return optional(commaSep1(rule));
}

module.exports = grammar({
  name: "plpgsql",
  // NOTE(chrde): https://github.com/tree-sitter/tree-sitter-javascript/blob/1ddbf1588c353edab37791cdcc9f17e56fb4ea73/grammar.js#L9
  extras: $ => [
    $.comment,
    /[\s\uFEFF\u2060\u200B\u00A0]/
  ],

  rules: {
    source_file: $ => repeat(
      choice(
        $.psql_statement,
        seq($._statement, ";")
      ),
    ),

    _statement: $ => choice(
      $.psql_statement,
      $.create_function_statement,
      $.drop_function_statement,
      $.create_table_statement,
      $.create_schema_statement,
      $.create_type_statement,
      $.select_statement,
      $.insert_statement,
      $.delete_statement,
      $.update_statement,
      $.grant_statement,
      $.create_trigger_statement,
      $.create_sequence_statement,
      $.create_index_statement,
      $.alter_table_statement,
      $.do_block,
    ),

    update_statement: $ => seq(
      optional($.with_query),
      kw("update"), $.identifier, optional(seq(optional(kw("as")), $.identifier)),
      kw("set"), commaSep1($.update_set),
      optional(seq(kw("from"), commaSep1($.from_item))),
      optional($.where_filter),
      optional($.returning),
    ),

    drop_function_statement: $ => seq(
      kw("drop"), kw("function"),
      commaSep1($.drop_function_item),
      optional(choice(kw("cascade"), kw("restrict")))
    ),

    drop_function_item: $ => seq(
      optional($.if_exists),
      $.identifier,
      optional(
        seq(
          "(",
          commaSep(
            choice($.var_declaration, $._type,)
          ),
          ")",
    ))),

    create_type_statement: $ => seq(
      kw("create"), kw("type"), $.identifier, optional(choice(
        seq(kw("as"), kw("enum"), "(", commaSep1($.string), ")"),
        seq(kw("as"), "(", commaSep1($.var_declaration), ")"),
      ))
    ),

    // TODO(chrde): values
    _with_query_statement: $ => choice(
      $.select_statement,
      $.insert_statement,
      $.delete_statement,
      $.update_statement,
    ),

    insert_statement: $ => seq(
      optional($.with_query),
      kw("insert"), kw("into"), $.identifier, optional($.as),
      optional($._list_of_identifiers),
      $.insert_items, optional($.insert_conflict),
      optional($.returning),
      optional($.into),
    ),
    insert_items: $ => choice(
      seq(kw("default"), kw("values")),
      seq(kw("values"), "(", commaSep($.insert_item), ")"),
      $.select_statement
    ),
    insert_item: $ => choice(
      kw("default"),
      $._value_expression,
    ),
    insert_conflict: $ => choice(
      seq(kw("on"), kw("conflict"), optional($.conflict_target), kw("do"), kw("nothing")),
      seq(
        kw("on"), kw("conflict"), $.conflict_target, kw("do"), kw("update"), kw("set"),
        commaSep1($.update_set), optional($.where_filter)
      ),
    ),
    conflict_target: $ => choice(
      seq(kw("on"), kw("constraint"), $.identifier),
      seq("(", commaSep($._value_expression), ")", ),
    ),
    update_set: $ => choice(
      seq($.identifier, "=", $.update_value),
      seq($._list_of_identifiers, "=", optional(kw("row")), "(", commaSep1($.update_value), ")"),
    ),
    update_value: $ => choice(kw("default"), $._value_expression),
    returning: $ => seq(kw("returning"), commaSep1($.select_item)),

    create_table_statement: $ => seq(
      kw("create"), optional($.temporary), optional(kw("unlogged")), kw("table"),
      optional($.if_not_exists), $.identifier,
      "(", commaSep($.create_table_item), ")",
    ),

    create_table_item: $ => choice(
      $.table_column_item,
      $.table_constraint,
    ),

    create_schema_statement: $ => seq(
      kw("create"), kw("schema"), optional($.if_not_exists), choice(
        seq($.identifier, optional($.schema_role)),
        $.schema_role,
      ),
    ),
        
    schema_role: $ => seq(
      kw("authorization"),
      choice($.identifier, kw("current_user"), kw("session_user")),
    ),

    create_index_statement: $ => seq(
      kw("create"), optional(kw("unique")), kw("index"), optional(kw("concurrently")),
      optional($.if_not_exists), optional($.identifier), kw("on"), $.identifier,
      optional($.index_using),
      "(", commaSep1($.index_col), ")",
      optional($.index_includes),
      optional($.where_filter),
    ),

    index_using: $ => seq(kw("using"), $.identifier),
    index_col: $ => choice(
      seq($.identifier, optional($.index_col_dir), optional($.index_col_nulls)),
      seq("(", $._value_expression, ")", optional($.index_col_dir), optional($.index_col_nulls)),
    ),
    index_col_dir: $ => choice(kw("asc"), kw("desc")),
    index_col_nulls: $ => choice(
      seq(kw("nulls"), kw("first")),
      seq(kw("nulls"), kw("last")),
    ),
    index_includes: $ => seq(kw("include"), $._list_of_identifiers),

    delete_statement: $ => seq(
      optional($.with_query),
      kw("delete"), kw("from"), $.identifier, optional(kw("as")), optional($.identifier),
      optional($.delete_using),
      optional($.where_filter),
      optional(seq(kw("returning"), commaSep1($.select_item))),
      optional($.into),
    ),

    delete_using: $ => seq(kw("using"), commaSep1($.from_item)),

    alter_table_statement: $ => seq(
      kw("alter"), kw("table"), optional($.if_exists), $.identifier,
      $.alter_table_change
    ),

    alter_table_change: $ => choice(
      commaSep1($.alter_table_action),
      $.alter_table_rename_column,
      $.alter_table_rename_constraint,
      $.alter_table_rename_table,
      $.alter_table_change_schema,
    ),

    alter_table_action: $ => choice(
      seq(kw("add"), $.table_constraint),
      seq(kw("add"), optional(kw("column")), optional($.if_not_exists), $.table_column_item),
      seq(kw("drop"), kw("constraint"), optional($.if_exists), $.identifier, optional($.alter_table_fk_ref_action)),
      seq(kw("drop"), optional(kw("column")), optional($.if_exists), $.identifier, optional($.alter_table_fk_ref_action)),
      seq(kw("alter"), optional(kw("column")), $.identifier, optional($.alter_column_action)),
    ),

    alter_column_action: $ => choice(
      seq(kw("set"), kw("default"), $._value_expression),
      seq(kw("drop"), kw("default")),
      seq(kw("set"), kw("not"), kw("null")),
      seq(kw("drop"), kw("not"), kw("null")),
      seq(kw("type"), $.alter_column_type),
      seq(kw("set"), kw("data"), kw("type"), $.alter_column_type),
    ),

    table_constraint: $ => choice(
      seq($.table_constraint_ty, optional($.constraint_when)),
      seq(kw("constraint"), $.identifier, $.table_constraint_ty, optional($.constraint_when)),
    ),

    constraint_when: $ => choice(
      kw("deferrable"),
      seq(kw("deferrable"), kw("initially"), kw("immediate")),
      seq(kw("deferrable"), kw("initially"), kw("deferred")),
    ),

    table_constraint_ty: $ => choice(
      seq(kw("check"), "(", $._value_expression, ")"),
      seq(kw("unique"), $._list_of_identifiers),
      seq(kw("primary"), kw("key"), $._list_of_identifiers),
      seq(kw("foreign"), kw("key"), $._list_of_identifiers, $.constraint_foreign_key),
    ),

    constraint_foreign_key: $ => seq(
      kw("references"), $.identifier,
      optional($._list_of_identifiers), repeat($.fk_action)
    ),

    fk_action: $ => choice(
      seq(kw("on"), kw("delete"), $.fk_ref_action),
      seq(kw("on"), kw("update"), $.fk_ref_action),
    ),

    fk_ref_action: $ => choice(
      seq(kw("no"), kw("action")),
      kw("restrict"),
      kw("cascade"),
      seq(kw("set"), kw("null")),
      seq(kw("set"), kw("default"))
    ),

    alter_column_type: $ => seq(
      $._type,
      optional(seq(kw("using"), $._value_expression)),
    ),
    alter_table_fk_ref_action: $ => choice(kw("restrict"), kw("cascade")),
    table_column_item: $ => seq($.identifier, $._type, repeat($.column_constraint)),

    column_constraint: $ => choice(
      seq(kw("constraint"), $.identifier, $.column_constraint_ty, optional($.constraint_when)),
      seq($.column_constraint_ty, optional($.constraint_when)),
    ),

    column_constraint_ty: $ => choice(
      seq(kw("not"), kw("null")),
      kw("null"),
      seq(kw("check"), "(",  $._value_expression, ")"),
      seq(kw("default"), $._value_expression),
      kw("unique"),
      seq(kw("primary"), kw("key")),
      $.constraint_foreign_key,
    ),

    alter_table_rename_column: $ => seq(
      kw("rename"), optional(kw("column")),
      $.identifier, kw("to"), $.identifier,
    ),
    alter_table_rename_constraint: $ => seq(
      kw("rename"), kw("constraint"),
      $.identifier, kw("to"), $.identifier,
    ),
    alter_table_rename_table: $ => seq(kw("rename"), kw("to"), $.identifier),
    alter_table_change_schema: $ => seq(kw("set"), kw("schema"), $.identifier),


    grant_statement: $ => seq(
      kw("grant"), $.grant_privileges,
      kw("on"), $.grant_targets,
      kw("to"), $.grant_roles,
    ),

    grant_roles: $ => commaSep1(choice(
      kw("public"),
      kw("current_user"),
      kw("session_user"),
      seq(optional(kw("group")), $.identifier),
    )),


    grant_privileges: $ => choice(
      seq(kw("all"), optional(kw("privileges"))),
      commaSep1($.identifier),
    ),

    grant_targets: $ => choice(
      seq(
        kw("all"),
        choice(kw("tables"), kw("sequences"), kw("functions")),
        kw("in"), kw("schema"), $.identifier
      ),
      seq(kw("sequence"), commaSep1($.identifier)),
      seq(optional(kw("table")), commaSep1($.identifier)),
      seq(kw("schema"), commaSep1($.identifier)),
      seq(
        choice(kw("function"), kw("procedure"), kw("routine")),
        commaSep1($.grant_function),
      ),
    ),

    grant_function: $ => seq(
      $.identifier,
      "(", 
      commaSep1(seq(optional($.identifier), $._type)),
      ")",
    ),

    grant_all_in_schema: $ => seq(kw("in"), kw("schema")), 

    psql_statement: $ => seq(
      "\\",
      repeat1($.identifier),
      /[\n\r]/,
    ),

    create_sequence_statement: $ => seq(
      kw("create"), optional($.temporary), kw("sequence"), optional($.if_not_exists),
      $.identifier,
      repeat(choice(
        $.as,
        $.sequence_increment,
        $.sequence_min,
        $.sequence_max,
        $.sequence_start,
        $.sequence_cache,
        $.sequence_cycle,
        $.sequence_owned,
      )),
    ),

    sequence_increment: $ => seq(kw("increment"), optional(kw("by")), $.number),
    sequence_min: $ => choice(
      seq(kw("no"), kw("minvalue")),
      seq(kw("minvalue"), $.number,),
    ),
    sequence_max: $ => choice(
      seq(kw("no"), kw("maxvalue")),
      seq(kw("maxvalue"), $.number,),
    ),
    sequence_start: $ => seq(kw("start"), optional(kw("with")), $.number),
    sequence_cache: $ => seq(kw("cache"), $.number),
    sequence_cycle: $ => seq(optional(kw("no")), kw("cycle")),
    sequence_owned: $ => seq(
      kw("owned"), kw("by"),
      choice(
        kw("none"),
        $.identifier
      ),
    ),

    create_trigger_statement: $ => seq(
      kw("create"), optional(kw("constraint")), kw("trigger"),
      $.identifier,
      $.trigger_when, $.trigger_event,
      kw("on"), $.identifier, optional($.trigger_scope),
      optional($.trigger_cond),
      $.trigger_exec,
    ),

    trigger_when: $ => choice(
      kw("before"),
      kw("after"),
      kw("instead of"),
    ),

    trigger_event: $ => separated1(
      kw("or"), choice(
        kw("insert"),
        kw("update"),
        kw("delete"),
        kw("truncate"),
      ),
    ),

    trigger_scope: $ => seq(
      optional(seq(kw("for"), optional(kw("each")))),
      choice(kw("statement"), kw("row")),
    ),

    trigger_exec: $ => seq(
      kw("execute"),
      optional(choice(kw("procedure"), kw("function"))),
      $.function_call,
    ),

    trigger_cond: $ => seq(
      kw("when"),
      "(", $._value_expression, ")",
    ),

    _plpgsql_statement: $ => seq(
      choice(
        $._statement,
        $.assign_statement,
        $.get_diagnostics_statement,
        $.return_statement,
        $.raise_statement,
        $.if_statement,
        $.for_statement,
        $.execute_statement,
        $.perform_statement,
      ),
      ";",
    ),

    get_diagnostics_statement: $ => seq(kw("get"), optional(kw("current")), kw("diagnostics"), $.assign_statement),

    for_statement: $ => seq(
      kw("for"), commaSep1($.identifier), kw("in"), choice(
        seq(
          optional(kw("reverse")),
          $._value_expression, "..", $._value_expression,
          optional(seq(kw("by"), $._value_expression))
        ),
        $.select_statement,
        $.execute_statement,
      ),
      kw("loop"),
      repeat($._plpgsql_statement),
      kw("end"), kw("loop")
    ),

    // TODO(chrde): https://www.postgresql.org/docs/13/plpgsql-errors-and-messages.html
    raise_statement: $ => seq(
      kw("raise"),
      optional(seq(
        optional($.identifier),
        $.string, 
        optional(seq(",", commaSep($._value_expression)))
      )),
    ),

    if_statement: $ => seq(
      kw("if"), $._value_expression, kw("then"), repeat1($._plpgsql_statement),
      repeat(seq(
        choice(kw("elsif"), kw("elseif")),
        $._value_expression, kw("then"), repeat1($._plpgsql_statement)
      )),
      optional(seq(kw("else"), repeat1($._plpgsql_statement))),
      kw("end"), kw("if"),
    ),

    execute_statement: $ => seq(
      kw("execute"),
      $._value_expression,
      optional($.into),
      optional($.execute_using),
    ),
    execute_using: $ => seq(kw("using"), commaSep1($._value_expression)),
    assign_statement: $ => seq($.identifier, choice("=", ":="), $._value_expression),
    return_statement: $ => seq(kw("return"), choice(
      seq(kw("query"), $.select_statement),
      seq(kw("query"), $.execute_statement),
      $._value_expression),
    ),
    perform_statement: $ => seq(kw("perform"), commaSep($.select_item)),

    do_block: $ => seq(
      kw("do"),
      $.block,
    ),

    select_statement: $ => prec.left(seq(
      optional($.with_query),
      kw("select"),
      commaSep($.select_item),
      optional($.into),
      optional($.select_from),
      optional($.select_where),
      optional($.select_group_by),
      optional($.select_having),
      optional($.select_order_by),
      optional($._select_limit_offset),
      optional($.into),
    )),

    with_query: $ => seq(kw("with"), commaSep1($.with_query_item)),
    with_query_item: $ => seq(
      $.identifier,
      optional($._list_of_identifiers),
      kw("as"),
      optional(choice(kw("materialized"), seq(kw("not"), kw("materialized")))),
      "(", $._with_query_statement, ")"
    ),
    into: $ => seq(kw("into"), optional(kw("strict")), commaSep1($.identifier)),
    select_having: $ => seq(kw("having"), $._value_expression),
    _select_limit_offset: $ => choice(
      seq($.select_limit, optional($.select_offset)),
      seq($.select_offset, optional($.select_limit)),
    ),
    select_limit: $ => seq(
      kw("limit"),
      choice(
        kw("all"),
        $._value_expression
      )
    ),
    select_offset: $ => seq(
      kw("offset"), $._value_expression,
      optional(choice(kw("row"), kw("rows")))
    ),
    // TODO(chrde): rollup, cube, grouping sets
    select_group_by: $ => prec(1, seq(kw("group"), kw("by"),
      choice(
        seq("(", commaSep1($._value_expression), ")"),
        commaSep1($._value_expression),
      ),
    )),
    select_order_by: $ => seq(kw("order"), kw("by"), commaSep1($.order_by_item)),
    order_by_item: $ => seq($._value_expression, optional($.order_by_direction)),
    order_by_direction: $ => choice(kw("asc"), kw("desc")),
    select_where: $ => $.where_filter,
    select_item: $ => seq(
      $._value_expression,
      optional(kw("as")),
      optional($.identifier)
    ),
    select_from: $ => seq(kw("from"), commaSep1($.from_item)),
    from_item: $ => prec.left(seq(
      // TODO(chrde): https://www.postgresql.org/docs/current/sql-select.html
      choice(
        $.from_select,
        $.from_table,
        $.from_function,
      ),
      repeat($.join_item),
    )),
    from_select: $ => seq("(", $.select_statement, ")", optional(kw("as")), $.identifier),
    from_table: $ => seq($.identifier, optional(kw("as")), optional($.identifier)),
    from_function: $ => seq(
      $.function_call,
      optional(choice(
        seq(kw("as"), $.identifier, optional($._list_of_identifiers)),
        seq($.identifier, optional($._list_of_identifiers)),
        seq(kw("as"), $._list_of_identifiers),
      )),
    ),

    join_item: $ => prec.left(choice(
      seq(kw("natural"), $.join_type, $.from_item),
      seq($.join_type, $.from_item, $.join_condition),
      seq(kw("cross"), kw("join"), $.from_item)
    )),
    join_condition: $ => choice(
      seq(kw("on"), $._value_expression),
      seq(kw("using"), $._list_of_identifiers)
    ),
    join_type: $ => seq(
      choice(
        optional(kw("inner")),
        seq(kw("left"), optional(kw("outer"))),
        seq(kw("right"), optional(kw("outer"))),
        seq(kw("full"), optional(kw("outer"))),
      ),
      kw("join")
    ),

    create_function_statement: $ => seq(
      kw("create"), optional($.or_replace), kw("function"),
      $.function_signature,
      $.function_return,
      kw("as"), choice(
        $.block,
        $.string,
      ),
      kw("language"), choice($.identifier, $.string),
      optional($.function_volatility),
      optional($.function_run_as),
    ),

    function_run_as: $ => seq(
      kw("security"),
      choice(kw("invoker"), kw("definer"))
    ),

    function_return: $ => seq(
      kw("returns"),
      choice(
        $.identifier,
        $.return_setof,
        $.return_table,
      ),
    ),
    return_setof: $ => seq(kw("setof"), $.identifier),
    return_table: $ => seq(kw("table"), "(", commaSep1($.var_declaration), ")"),

    function_volatility: $ => choice(
      kw("immutable"),
      kw("stable"),
      kw("volatile"),
    ),

    block: $ => seq(
      $.dollar_quote,
      repeat($.declarations),
      $.body,
      $.dollar_quote,
    ),

    body: $ => seq(
      kw("begin"),
      repeat($._plpgsql_statement),
      kw("end"),
      optional(";"),
    ),

    dollar_quote: $ => seq("$", optional($.identifier), "$"),

    declarations: $ => seq(
      kw("declare"),
      repeat($.var_definition),
    ),

    var_definition: $ => seq(
      $.var_declaration,
      optional(seq(":=", $._value_expression)),
      ";",
    ),

    function_signature: $ => seq(
      $.identifier,
      $.function_parameters,
    ),

    function_parameters: $ => seq(
      "(",
      commaSep($.var_declaration),
      optional(seq(kw("default"), field("default_value", ($._value_expression)))),
      ")"
    ),

    var_declaration: $ => seq(
      field("name", $.identifier),
      field("type", $._type),
    ),

    where_filter: $ => seq(kw("where"), $._value_expression),
    or_replace: $ => seq(kw("or"), kw("replace")),
    temporary: $ => choice(kw("temp"), kw("temporary")),
    if_not_exists: $ => seq(kw("if"), kw("not"), kw("exists")),
    if_exists: $ => seq(kw("if"), kw("exists")),
    as: $ => seq(kw("as"), $.identifier),

    _type: $ => seq(
      choice($.predefined_types, $.identifier),
      optional(choice(
        repeat1(seq("[", "]")),
        kw("%rowtype"),
        kw("%type")))
    ),

// predefined_type:
//   | BIGINT { BigInt }
//   | BIT VARYING? l = type_length? { BitVarying(l) }
//   | BOOLEAN { Boolean }
//   | CHAR VARYING? l = type_length? { Char(l) }
//   | CHARACTER VARYING? l = type_length? { Char(l) }
//   | DEC p = precision_param? { Dec(p) }
//   | DECIMAL p = precision_param? { Decimal(p) }
//   | DOUBLE PRECISION { Double }
//   | FLOAT p = precision_param? { Float(p) }
//   | INT { Int }
//   | INTEGER { Integer }
//   | INTERVAL interval = interval_field? l = type_length? { Interval(interval, l) }
//   | NCHAR VARYING? l = type_length? { Nchar(l) }
//   | NUMERIC p = precision_param? { Numeric(p) }
//   | REAL { Real }
//   | SMALLINT { SmallInt }
//   | TEXT { Text }
//   (* | TIME l = type_length? (1* NOTE(chrde): what here? *1) *)
//   | TIME l = type_length? WITH TIME ZONE { TimeTz(l) }
//   | TIME l = type_length? WITHOUT TIME ZONE { Time(l) }
//   (* | TIMESTAMP l = type_length? (1* NOTE(chrde): what here? *1) *)
//   | TIMESTAMP l = type_length? WITH TIME ZONE { TimestampTz(l) }
//   | TIMESTAMPTZ l = type_length? { TimestampTz(l) }
//   | TIMESTAMP l = type_length? WITHOUT TIME ZONE { Timestamp(l) }
//   | VARCHAR l = type_length? { VarChar(l) }
//   (* | schema_qualified_name_nontype (LEFT_PAREN vex (COMMA vex)* RIGHT_PAREN)? *)
    // TODO(chrde): moar types!!
    predefined_types: $ => choice(
      seq(kw("numeric"), optional($.precision))
    ),

    precision: $ => seq("(", $.number, optional(seq(",", $.number)), ")"),

    string: $ => seq(
      "'",
      repeat(choice(
        prec(1, /''/),
        prec(2, /[^']/),
      )),
       "'",
    ),

    // NOTE(chrde): taken from https://github.com/tree-sitter/tree-sitter-javascript/blob/1ddbf1588c353edab37791cdcc9f17e56fb4ea73/grammar.js#L899
    comment: $ => token(choice(
      seq('--', /.*/),
      seq(
        '/*',
        /[^*]*\*+([^/*][^*]*\*+)*/,
        '/'
      )
    )),

    _value_expression: $ => choice(
      $.number,
      $.dollar_quote_string,
      $.string,
      $.true,
      $.false,
      $.null,
      $.star,
      seq("(", $.select_statement, ")"),
      seq("(", commaSep1($._value_expression), ")"),
      $.function_call,
      $.op_expression,
      $.time_expression,
      // TODO(chrde): this one feels a bit hacky? perhaps move to identifier regexp
      seq($.identifier, ".", $.star),
      $.identifier,
    ),

    // TODO(chrde): it does not handle nested dollar quotes... perhaps move to an external scanner?
    dollar_quote_string: $ => seq(
      "$", $._identifier, "$",
        /(([^$]+)|(%\d+\$s)|(\$\d+))+/,
        //                     ^
        //                     |- matches $1 (execute ... using placeholders)
        //           ^
        //           |- matches %d1s (format placeholders)
        //  ^
        //  |- matches anything other than $
      "$", $._identifier, "$",
    ),

    time_expression: $ => choice(
      seq($.identifier, kw("at"), kw("time"), kw("zone"), $._value_expression),
      // TODO(chrde): this is plain wrong - https://www.postgresql.org/docs/13/datatype-datetime.html
      seq(kw("interval"), $.string, optional($._interval_fields)),
    ),

    _interval_fields: $ => choice(
      kw("year"), kw("month"), kw("day"), kw("hour"), kw("minute"), kw("second"),
      seq(kw("year"), kw("to"), kw("month")),
      seq(kw("day"), kw("to"), kw("hour")),
      seq(kw("day"), kw("to"), kw("minute")),
      seq(kw("day"), kw("to"), kw("second")),
      seq(kw("hour"), kw("to"), kw("minute")),
      seq(kw("hour"), kw("to"), kw("second")),
      seq(kw("minute"), kw("to"), kw("second")),
    ),

    function_call: $ => seq(
      $.identifier,
      "(",
      choice(
        $.select_statement,
        commaSep($._value_expression),
      ),
      ")"
    ),

    op_expression: $ => choice(
      prec.left(12, seq($._value_expression, $.cast, $.identifier)),
      // array access
      prec.right(10, seq(choice($.minus, $.plus), $._value_expression)),
      // ^
      prec.left(8, seq($._value_expression, choice("*", "/", "%"), $._value_expression,)),
      prec.left(7, seq($._value_expression, choice("-", "+"), $._value_expression,)),
      prec.left(6, seq($._value_expression, $.other_op, $._value_expression)),
      prec.left(5, seq($._value_expression, $.contains_op, $._value_expression,)),
      prec.left(4, seq($._value_expression, $.comparison_op, $._value_expression,)),
      prec.left(3, seq($._value_expression, $.comparison_kw, $._value_expression,)),
      prec.left(3, seq($._value_expression, $.comparison_null)),
      prec.right(2, seq($.not, $._value_expression)),
      prec.left(1, seq($._value_expression, choice($.and, $.or), $._value_expression,)),
    ),

    _list_of_identifiers: $ => seq("(", commaSep($.identifier), ")"),

    // TODO(chrde): https://www.postgresql.org/docs/13/sql-syntax-lexical.html
    comparison_op: $ => choice("<", ">", "=", "<=", ">=", "<>", "!="),
    // TODO(chrde): is there a better name other than `contains_op`?
    contains_op: $ => choice(kw("between"), kw("in"), kw("like"), kw("ilike")),
    comparison_null: $ => choice(
      kw("is null"),
      kw("isnull"),
      kw("is not null"),
      kw("notnull"),
    ),
    comparison_kw: $ => choice(
      kw("is"),
      kw("is distinct from"),
      kw("is not distinct from")
    ),
    // TODO(chrde): this should be a regex
    other_op: $ => choice("||", "<@", "@>", "<<", ">>", "&&", "&<", "&>", "-|-"),
    cast: $ => "::",
    minus: $ => "-",
    plus: $ => "+",
    not: $ => kw("not"),
    and: $ => kw("and"),
    or: $ => kw("or"),
    true: $ => kw("true"),
    false: $ => kw("false"),
    null: $ => kw("null"),
    star: $ => "*",
    any: $ => /.*/,
    number: $ => /-?\d+/,
    identifier: $ => $._identifier,
    _identifier: $ => /[a-zA-Z0-9_]+(\.?[a-zA-Z0-9_]+)*/,
    //                                ^
    //                                |- we dont want to match consecutive dots, e.g: 1..2 consists of 3 tokens
  }
});
