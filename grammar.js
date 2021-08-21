function kw(keyword, aliasAsWord = true) {
  let result = new RegExp(keyword
    .split('')
    .map(l => l !== l.toUpperCase() ? `[${l}${l.toUpperCase()}]` : l)
    .join('')
  );
  if (aliasAsWord) {
    result = alias(result, keyword);
  }
  return result;
}

function delimited(left, rule, right = left) {
  return seq(left, rule, right)
}

function separated(separator, rule) {
  return choice(
    optional(rule),
    seq(rule, repeat1(seq(",", rule))))
}

module.exports = grammar({
  name: 'plpgsql',

  rules: {
    source_file: $ => repeat($._statement),

    _statement: $ => seq(
      choice(
        $.create_function_statement,
      ),
      ";"
    ),

    create_function_statement: $ => seq(
      kw("CREATE"), optional($.or_replace), kw("FUNCTION"),
      $.function_signature,
      optional(seq(kw("RETURNS"), $.identifier)),
      kw("AS"), $.block,
      kw("LANGUAGE"), $.identifier,
      optional($.function_volatility)
    ),

    function_volatility: $ => choice(
      kw("IMMUTABLE"),
      kw("STABLE"),
      kw("VOLATILE"),
    ),

    block: $ => seq(
      $.dollar_quote,
      $.dollar_quote,
    ),

    dollar_quote: $ => delimited("$", optional($.identifier)),

    function_signature: $ => seq(
      $.identifier,
      $.function_parameters,
    ),

    function_parameters: $ => seq(
      "(",
      separated(",", $.function_parameter),
      ")"
    ),

    function_parameter: $ => seq(
      field("name", $.identifier),
      field("type", $._type),
    ),

    or_replace: $ => seq("OR", "REPLACE"),

    _type: $ => choice(
      $.identifier,
      seq($._type, "[", "]"),
    ),

    identifier: $ => /[a-zA-Z0-9_]+[.a-zA-Z0-9_]*/,
  }
});
