#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 13
#define STATE_COUNT 61
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 32
#define ALIAS_COUNT 0
#define TOKEN_COUNT 19
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 2
#define MAX_ALIAS_SEQUENCE_LENGTH 11
#define PRODUCTION_ID_COUNT 2

enum {
  anon_sym_SEMI = 1,
  aux_sym_create_function_statement_token1 = 2,
  aux_sym_create_function_statement_token2 = 3,
  aux_sym_create_function_statement_token3 = 4,
  aux_sym_create_function_statement_token4 = 5,
  aux_sym_create_function_statement_token5 = 6,
  aux_sym_function_volatility_token1 = 7,
  aux_sym_function_volatility_token2 = 8,
  aux_sym_function_volatility_token3 = 9,
  anon_sym_DOLLAR = 10,
  anon_sym_LPAREN = 11,
  anon_sym_COMMA = 12,
  anon_sym_RPAREN = 13,
  anon_sym_OR = 14,
  anon_sym_REPLACE = 15,
  anon_sym_LBRACK = 16,
  anon_sym_RBRACK = 17,
  sym_identifier = 18,
  sym_source_file = 19,
  sym__statement = 20,
  sym_create_function_statement = 21,
  sym_function_volatility = 22,
  sym_block = 23,
  sym_dollar_quote = 24,
  sym_function_signature = 25,
  sym_function_parameters = 26,
  sym_function_parameter = 27,
  sym_or_replace = 28,
  sym__type = 29,
  aux_sym_source_file_repeat1 = 30,
  aux_sym_function_parameters_repeat1 = 31,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_SEMI] = ";",
  [aux_sym_create_function_statement_token1] = "CREATE",
  [aux_sym_create_function_statement_token2] = "FUNCTION",
  [aux_sym_create_function_statement_token3] = "RETURNS",
  [aux_sym_create_function_statement_token4] = "AS",
  [aux_sym_create_function_statement_token5] = "LANGUAGE",
  [aux_sym_function_volatility_token1] = "IMMUTABLE",
  [aux_sym_function_volatility_token2] = "STABLE",
  [aux_sym_function_volatility_token3] = "VOLATILE",
  [anon_sym_DOLLAR] = "$",
  [anon_sym_LPAREN] = "(",
  [anon_sym_COMMA] = ",",
  [anon_sym_RPAREN] = ")",
  [anon_sym_OR] = "OR",
  [anon_sym_REPLACE] = "REPLACE",
  [anon_sym_LBRACK] = "[",
  [anon_sym_RBRACK] = "]",
  [sym_identifier] = "identifier",
  [sym_source_file] = "source_file",
  [sym__statement] = "_statement",
  [sym_create_function_statement] = "create_function_statement",
  [sym_function_volatility] = "function_volatility",
  [sym_block] = "block",
  [sym_dollar_quote] = "dollar_quote",
  [sym_function_signature] = "function_signature",
  [sym_function_parameters] = "function_parameters",
  [sym_function_parameter] = "function_parameter",
  [sym_or_replace] = "or_replace",
  [sym__type] = "_type",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_function_parameters_repeat1] = "function_parameters_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_SEMI] = anon_sym_SEMI,
  [aux_sym_create_function_statement_token1] = aux_sym_create_function_statement_token1,
  [aux_sym_create_function_statement_token2] = aux_sym_create_function_statement_token2,
  [aux_sym_create_function_statement_token3] = aux_sym_create_function_statement_token3,
  [aux_sym_create_function_statement_token4] = aux_sym_create_function_statement_token4,
  [aux_sym_create_function_statement_token5] = aux_sym_create_function_statement_token5,
  [aux_sym_function_volatility_token1] = aux_sym_function_volatility_token1,
  [aux_sym_function_volatility_token2] = aux_sym_function_volatility_token2,
  [aux_sym_function_volatility_token3] = aux_sym_function_volatility_token3,
  [anon_sym_DOLLAR] = anon_sym_DOLLAR,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [anon_sym_OR] = anon_sym_OR,
  [anon_sym_REPLACE] = anon_sym_REPLACE,
  [anon_sym_LBRACK] = anon_sym_LBRACK,
  [anon_sym_RBRACK] = anon_sym_RBRACK,
  [sym_identifier] = sym_identifier,
  [sym_source_file] = sym_source_file,
  [sym__statement] = sym__statement,
  [sym_create_function_statement] = sym_create_function_statement,
  [sym_function_volatility] = sym_function_volatility,
  [sym_block] = sym_block,
  [sym_dollar_quote] = sym_dollar_quote,
  [sym_function_signature] = sym_function_signature,
  [sym_function_parameters] = sym_function_parameters,
  [sym_function_parameter] = sym_function_parameter,
  [sym_or_replace] = sym_or_replace,
  [sym__type] = sym__type,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym_function_parameters_repeat1] = aux_sym_function_parameters_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_SEMI] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_create_function_statement_token1] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_create_function_statement_token2] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_create_function_statement_token3] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_create_function_statement_token4] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_create_function_statement_token5] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_function_volatility_token1] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_function_volatility_token2] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_function_volatility_token3] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DOLLAR] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COMMA] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_OR] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_REPLACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACK] = {
    .visible = true,
    .named = false,
  },
  [sym_identifier] = {
    .visible = true,
    .named = true,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym__statement] = {
    .visible = false,
    .named = true,
  },
  [sym_create_function_statement] = {
    .visible = true,
    .named = true,
  },
  [sym_function_volatility] = {
    .visible = true,
    .named = true,
  },
  [sym_block] = {
    .visible = true,
    .named = true,
  },
  [sym_dollar_quote] = {
    .visible = true,
    .named = true,
  },
  [sym_function_signature] = {
    .visible = true,
    .named = true,
  },
  [sym_function_parameters] = {
    .visible = true,
    .named = true,
  },
  [sym_function_parameter] = {
    .visible = true,
    .named = true,
  },
  [sym_or_replace] = {
    .visible = true,
    .named = true,
  },
  [sym__type] = {
    .visible = false,
    .named = true,
  },
  [aux_sym_source_file_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_function_parameters_repeat1] = {
    .visible = false,
    .named = false,
  },
};

enum {
  field_name = 1,
  field_type = 2,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_name] = "name",
  [field_type] = "type",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 2},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_name, 0},
    {field_type, 1},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(53);
      if (lookahead == '$') ADVANCE(63);
      if (lookahead == '(') ADVANCE(64);
      if (lookahead == ')') ADVANCE(66);
      if (lookahead == ',') ADVANCE(65);
      if (lookahead == ';') ADVANCE(54);
      if (lookahead == 'A') ADVANCE(42);
      if (lookahead == 'C') ADVANCE(40);
      if (lookahead == 'F') ADVANCE(49);
      if (lookahead == 'I') ADVANCE(31);
      if (lookahead == 'L') ADVANCE(4);
      if (lookahead == 'O') ADVANCE(39);
      if (lookahead == 'R') ADVANCE(13);
      if (lookahead == 'S') ADVANCE(45);
      if (lookahead == 'V') ADVANCE(36);
      if (lookahead == '[') ADVANCE(69);
      if (lookahead == ']') ADVANCE(70);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      END_STATE();
    case 1:
      if (lookahead == '$') ADVANCE(63);
      if (lookahead == ')') ADVANCE(66);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(1)
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(71);
      END_STATE();
    case 2:
      if (lookahead == 'A') ADVANCE(9);
      END_STATE();
    case 3:
      if (lookahead == 'A') ADVANCE(47);
      END_STATE();
    case 4:
      if (lookahead == 'A') ADVANCE(33);
      END_STATE();
    case 5:
      if (lookahead == 'A') ADVANCE(12);
      END_STATE();
    case 6:
      if (lookahead == 'A') ADVANCE(22);
      END_STATE();
    case 7:
      if (lookahead == 'A') ADVANCE(46);
      END_STATE();
    case 8:
      if (lookahead == 'A') ADVANCE(10);
      END_STATE();
    case 9:
      if (lookahead == 'B') ADVANCE(26);
      END_STATE();
    case 10:
      if (lookahead == 'B') ADVANCE(29);
      END_STATE();
    case 11:
      if (lookahead == 'C') ADVANCE(44);
      END_STATE();
    case 12:
      if (lookahead == 'C') ADVANCE(16);
      END_STATE();
    case 13:
      if (lookahead == 'E') ADVANCE(38);
      END_STATE();
    case 14:
      if (lookahead == 'E') ADVANCE(55);
      END_STATE();
    case 15:
      if (lookahead == 'E') ADVANCE(61);
      END_STATE();
    case 16:
      if (lookahead == 'E') ADVANCE(68);
      END_STATE();
    case 17:
      if (lookahead == 'E') ADVANCE(59);
      END_STATE();
    case 18:
      if (lookahead == 'E') ADVANCE(62);
      END_STATE();
    case 19:
      if (lookahead == 'E') ADVANCE(60);
      END_STATE();
    case 20:
      if (lookahead == 'E') ADVANCE(3);
      END_STATE();
    case 21:
      if (lookahead == 'G') ADVANCE(51);
      END_STATE();
    case 22:
      if (lookahead == 'G') ADVANCE(17);
      END_STATE();
    case 23:
      if (lookahead == 'I') ADVANCE(37);
      END_STATE();
    case 24:
      if (lookahead == 'I') ADVANCE(28);
      END_STATE();
    case 25:
      if (lookahead == 'L') ADVANCE(7);
      END_STATE();
    case 26:
      if (lookahead == 'L') ADVANCE(15);
      END_STATE();
    case 27:
      if (lookahead == 'L') ADVANCE(5);
      END_STATE();
    case 28:
      if (lookahead == 'L') ADVANCE(18);
      END_STATE();
    case 29:
      if (lookahead == 'L') ADVANCE(19);
      END_STATE();
    case 30:
      if (lookahead == 'M') ADVANCE(52);
      END_STATE();
    case 31:
      if (lookahead == 'M') ADVANCE(30);
      END_STATE();
    case 32:
      if (lookahead == 'N') ADVANCE(11);
      END_STATE();
    case 33:
      if (lookahead == 'N') ADVANCE(21);
      END_STATE();
    case 34:
      if (lookahead == 'N') ADVANCE(56);
      END_STATE();
    case 35:
      if (lookahead == 'N') ADVANCE(43);
      END_STATE();
    case 36:
      if (lookahead == 'O') ADVANCE(25);
      END_STATE();
    case 37:
      if (lookahead == 'O') ADVANCE(34);
      END_STATE();
    case 38:
      if (lookahead == 'P') ADVANCE(27);
      if (lookahead == 'T') ADVANCE(50);
      END_STATE();
    case 39:
      if (lookahead == 'R') ADVANCE(67);
      END_STATE();
    case 40:
      if (lookahead == 'R') ADVANCE(20);
      END_STATE();
    case 41:
      if (lookahead == 'R') ADVANCE(35);
      END_STATE();
    case 42:
      if (lookahead == 'S') ADVANCE(58);
      END_STATE();
    case 43:
      if (lookahead == 'S') ADVANCE(57);
      END_STATE();
    case 44:
      if (lookahead == 'T') ADVANCE(23);
      END_STATE();
    case 45:
      if (lookahead == 'T') ADVANCE(2);
      END_STATE();
    case 46:
      if (lookahead == 'T') ADVANCE(24);
      END_STATE();
    case 47:
      if (lookahead == 'T') ADVANCE(14);
      END_STATE();
    case 48:
      if (lookahead == 'T') ADVANCE(8);
      END_STATE();
    case 49:
      if (lookahead == 'U') ADVANCE(32);
      END_STATE();
    case 50:
      if (lookahead == 'U') ADVANCE(41);
      END_STATE();
    case 51:
      if (lookahead == 'U') ADVANCE(6);
      END_STATE();
    case 52:
      if (lookahead == 'U') ADVANCE(48);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(anon_sym_SEMI);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(aux_sym_create_function_statement_token1);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(aux_sym_create_function_statement_token2);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(aux_sym_create_function_statement_token3);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(aux_sym_create_function_statement_token4);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(aux_sym_create_function_statement_token5);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(aux_sym_function_volatility_token1);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(aux_sym_function_volatility_token2);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(aux_sym_function_volatility_token3);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(anon_sym_DOLLAR);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(anon_sym_OR);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(anon_sym_REPLACE);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '.') ADVANCE(72);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(71);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(72);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 0},
  [3] = {.lex_state = 0},
  [4] = {.lex_state = 0},
  [5] = {.lex_state = 0},
  [6] = {.lex_state = 0},
  [7] = {.lex_state = 0},
  [8] = {.lex_state = 0},
  [9] = {.lex_state = 0},
  [10] = {.lex_state = 0},
  [11] = {.lex_state = 0},
  [12] = {.lex_state = 0},
  [13] = {.lex_state = 0},
  [14] = {.lex_state = 0},
  [15] = {.lex_state = 1},
  [16] = {.lex_state = 0},
  [17] = {.lex_state = 0},
  [18] = {.lex_state = 0},
  [19] = {.lex_state = 1},
  [20] = {.lex_state = 1},
  [21] = {.lex_state = 0},
  [22] = {.lex_state = 1},
  [23] = {.lex_state = 0},
  [24] = {.lex_state = 0},
  [25] = {.lex_state = 1},
  [26] = {.lex_state = 0},
  [27] = {.lex_state = 1},
  [28] = {.lex_state = 0},
  [29] = {.lex_state = 0},
  [30] = {.lex_state = 0},
  [31] = {.lex_state = 0},
  [32] = {.lex_state = 0},
  [33] = {.lex_state = 0},
  [34] = {.lex_state = 0},
  [35] = {.lex_state = 0},
  [36] = {.lex_state = 0},
  [37] = {.lex_state = 0},
  [38] = {.lex_state = 0},
  [39] = {.lex_state = 0},
  [40] = {.lex_state = 1},
  [41] = {.lex_state = 1},
  [42] = {.lex_state = 0},
  [43] = {.lex_state = 0},
  [44] = {.lex_state = 0},
  [45] = {.lex_state = 0},
  [46] = {.lex_state = 1},
  [47] = {.lex_state = 0},
  [48] = {.lex_state = 1},
  [49] = {.lex_state = 0},
  [50] = {.lex_state = 1},
  [51] = {.lex_state = 0},
  [52] = {.lex_state = 0},
  [53] = {.lex_state = 0},
  [54] = {.lex_state = 0},
  [55] = {.lex_state = 0},
  [56] = {.lex_state = 1},
  [57] = {.lex_state = 0},
  [58] = {.lex_state = 0},
  [59] = {.lex_state = 0},
  [60] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_SEMI] = ACTIONS(1),
    [aux_sym_create_function_statement_token1] = ACTIONS(1),
    [aux_sym_create_function_statement_token2] = ACTIONS(1),
    [aux_sym_create_function_statement_token3] = ACTIONS(1),
    [aux_sym_create_function_statement_token4] = ACTIONS(1),
    [aux_sym_create_function_statement_token5] = ACTIONS(1),
    [aux_sym_function_volatility_token1] = ACTIONS(1),
    [aux_sym_function_volatility_token2] = ACTIONS(1),
    [aux_sym_function_volatility_token3] = ACTIONS(1),
    [anon_sym_DOLLAR] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_OR] = ACTIONS(1),
    [anon_sym_REPLACE] = ACTIONS(1),
    [anon_sym_LBRACK] = ACTIONS(1),
    [anon_sym_RBRACK] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(45),
    [sym__statement] = STATE(4),
    [sym_create_function_statement] = STATE(59),
    [aux_sym_source_file_repeat1] = STATE(4),
    [ts_builtin_sym_end] = ACTIONS(3),
    [aux_sym_create_function_statement_token1] = ACTIONS(5),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 3,
    ACTIONS(7), 1,
      anon_sym_SEMI,
    STATE(60), 1,
      sym_function_volatility,
    ACTIONS(9), 3,
      aux_sym_function_volatility_token1,
      aux_sym_function_volatility_token2,
      aux_sym_function_volatility_token3,
  [12] = 3,
    ACTIONS(11), 1,
      anon_sym_SEMI,
    STATE(58), 1,
      sym_function_volatility,
    ACTIONS(9), 3,
      aux_sym_function_volatility_token1,
      aux_sym_function_volatility_token2,
      aux_sym_function_volatility_token3,
  [24] = 4,
    ACTIONS(5), 1,
      aux_sym_create_function_statement_token1,
    ACTIONS(13), 1,
      ts_builtin_sym_end,
    STATE(59), 1,
      sym_create_function_statement,
    STATE(7), 2,
      sym__statement,
      aux_sym_source_file_repeat1,
  [38] = 3,
    ACTIONS(15), 1,
      anon_sym_SEMI,
    STATE(57), 1,
      sym_function_volatility,
    ACTIONS(9), 3,
      aux_sym_function_volatility_token1,
      aux_sym_function_volatility_token2,
      aux_sym_function_volatility_token3,
  [50] = 3,
    ACTIONS(17), 1,
      anon_sym_SEMI,
    STATE(52), 1,
      sym_function_volatility,
    ACTIONS(9), 3,
      aux_sym_function_volatility_token1,
      aux_sym_function_volatility_token2,
      aux_sym_function_volatility_token3,
  [62] = 4,
    ACTIONS(19), 1,
      ts_builtin_sym_end,
    ACTIONS(21), 1,
      aux_sym_create_function_statement_token1,
    STATE(59), 1,
      sym_create_function_statement,
    STATE(7), 2,
      sym__statement,
      aux_sym_source_file_repeat1,
  [76] = 2,
    ACTIONS(26), 1,
      anon_sym_LBRACK,
    ACTIONS(24), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [84] = 3,
    ACTIONS(28), 1,
      aux_sym_create_function_statement_token2,
    ACTIONS(30), 1,
      anon_sym_OR,
    STATE(37), 1,
      sym_or_replace,
  [94] = 1,
    ACTIONS(32), 3,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
  [100] = 3,
    ACTIONS(34), 1,
      anon_sym_DOLLAR,
    STATE(29), 1,
      sym_dollar_quote,
    STATE(53), 1,
      sym_block,
  [110] = 3,
    ACTIONS(36), 1,
      anon_sym_COMMA,
    ACTIONS(39), 1,
      anon_sym_RPAREN,
    STATE(12), 1,
      aux_sym_function_parameters_repeat1,
  [120] = 3,
    ACTIONS(34), 1,
      anon_sym_DOLLAR,
    STATE(29), 1,
      sym_dollar_quote,
    STATE(44), 1,
      sym_block,
  [130] = 3,
    ACTIONS(41), 1,
      anon_sym_COMMA,
    ACTIONS(43), 1,
      anon_sym_RPAREN,
    STATE(12), 1,
      aux_sym_function_parameters_repeat1,
  [140] = 3,
    ACTIONS(45), 1,
      anon_sym_RPAREN,
    ACTIONS(47), 1,
      sym_identifier,
    STATE(17), 1,
      sym_function_parameter,
  [150] = 3,
    ACTIONS(34), 1,
      anon_sym_DOLLAR,
    STATE(29), 1,
      sym_dollar_quote,
    STATE(39), 1,
      sym_block,
  [160] = 3,
    ACTIONS(41), 1,
      anon_sym_COMMA,
    ACTIONS(49), 1,
      anon_sym_RPAREN,
    STATE(14), 1,
      aux_sym_function_parameters_repeat1,
  [170] = 3,
    ACTIONS(34), 1,
      anon_sym_DOLLAR,
    STATE(29), 1,
      sym_dollar_quote,
    STATE(47), 1,
      sym_block,
  [180] = 2,
    ACTIONS(47), 1,
      sym_identifier,
    STATE(35), 1,
      sym_function_parameter,
  [187] = 2,
    ACTIONS(51), 1,
      sym_identifier,
    STATE(23), 1,
      sym_function_signature,
  [194] = 1,
    ACTIONS(53), 2,
      aux_sym_create_function_statement_token3,
      aux_sym_create_function_statement_token4,
  [199] = 2,
    ACTIONS(51), 1,
      sym_identifier,
    STATE(32), 1,
      sym_function_signature,
  [206] = 2,
    ACTIONS(55), 1,
      aux_sym_create_function_statement_token3,
    ACTIONS(57), 1,
      aux_sym_create_function_statement_token4,
  [213] = 1,
    ACTIONS(59), 2,
      aux_sym_create_function_statement_token3,
      aux_sym_create_function_statement_token4,
  [218] = 2,
    ACTIONS(61), 1,
      sym_identifier,
    STATE(8), 1,
      sym__type,
  [225] = 1,
    ACTIONS(63), 2,
      ts_builtin_sym_end,
      aux_sym_create_function_statement_token1,
  [230] = 2,
    ACTIONS(65), 1,
      anon_sym_DOLLAR,
    ACTIONS(67), 1,
      sym_identifier,
  [237] = 2,
    ACTIONS(69), 1,
      anon_sym_LPAREN,
    STATE(21), 1,
      sym_function_parameters,
  [244] = 2,
    ACTIONS(34), 1,
      anon_sym_DOLLAR,
    STATE(49), 1,
      sym_dollar_quote,
  [251] = 1,
    ACTIONS(71), 2,
      aux_sym_create_function_statement_token5,
      anon_sym_DOLLAR,
  [256] = 1,
    ACTIONS(73), 2,
      aux_sym_create_function_statement_token3,
      aux_sym_create_function_statement_token4,
  [261] = 2,
    ACTIONS(75), 1,
      aux_sym_create_function_statement_token3,
    ACTIONS(77), 1,
      aux_sym_create_function_statement_token4,
  [268] = 1,
    ACTIONS(79), 2,
      aux_sym_create_function_statement_token3,
      aux_sym_create_function_statement_token4,
  [273] = 1,
    ACTIONS(81), 2,
      aux_sym_create_function_statement_token5,
      anon_sym_DOLLAR,
  [278] = 1,
    ACTIONS(39), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [283] = 1,
    ACTIONS(83), 1,
      anon_sym_RBRACK,
  [287] = 1,
    ACTIONS(85), 1,
      aux_sym_create_function_statement_token2,
  [291] = 1,
    ACTIONS(87), 1,
      aux_sym_create_function_statement_token4,
  [295] = 1,
    ACTIONS(89), 1,
      aux_sym_create_function_statement_token5,
  [299] = 1,
    ACTIONS(91), 1,
      sym_identifier,
  [303] = 1,
    ACTIONS(93), 1,
      sym_identifier,
  [307] = 1,
    ACTIONS(95), 1,
      anon_sym_DOLLAR,
  [311] = 1,
    ACTIONS(97), 1,
      aux_sym_create_function_statement_token2,
  [315] = 1,
    ACTIONS(99), 1,
      aux_sym_create_function_statement_token5,
  [319] = 1,
    ACTIONS(101), 1,
      ts_builtin_sym_end,
  [323] = 1,
    ACTIONS(103), 1,
      sym_identifier,
  [327] = 1,
    ACTIONS(105), 1,
      aux_sym_create_function_statement_token5,
  [331] = 1,
    ACTIONS(107), 1,
      sym_identifier,
  [335] = 1,
    ACTIONS(109), 1,
      aux_sym_create_function_statement_token5,
  [339] = 1,
    ACTIONS(111), 1,
      sym_identifier,
  [343] = 1,
    ACTIONS(113), 1,
      anon_sym_SEMI,
  [347] = 1,
    ACTIONS(15), 1,
      anon_sym_SEMI,
  [351] = 1,
    ACTIONS(115), 1,
      aux_sym_create_function_statement_token5,
  [355] = 1,
    ACTIONS(117), 1,
      anon_sym_REPLACE,
  [359] = 1,
    ACTIONS(119), 1,
      aux_sym_create_function_statement_token4,
  [363] = 1,
    ACTIONS(121), 1,
      sym_identifier,
  [367] = 1,
    ACTIONS(11), 1,
      anon_sym_SEMI,
  [371] = 1,
    ACTIONS(7), 1,
      anon_sym_SEMI,
  [375] = 1,
    ACTIONS(123), 1,
      anon_sym_SEMI,
  [379] = 1,
    ACTIONS(125), 1,
      anon_sym_SEMI,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 12,
  [SMALL_STATE(4)] = 24,
  [SMALL_STATE(5)] = 38,
  [SMALL_STATE(6)] = 50,
  [SMALL_STATE(7)] = 62,
  [SMALL_STATE(8)] = 76,
  [SMALL_STATE(9)] = 84,
  [SMALL_STATE(10)] = 94,
  [SMALL_STATE(11)] = 100,
  [SMALL_STATE(12)] = 110,
  [SMALL_STATE(13)] = 120,
  [SMALL_STATE(14)] = 130,
  [SMALL_STATE(15)] = 140,
  [SMALL_STATE(16)] = 150,
  [SMALL_STATE(17)] = 160,
  [SMALL_STATE(18)] = 170,
  [SMALL_STATE(19)] = 180,
  [SMALL_STATE(20)] = 187,
  [SMALL_STATE(21)] = 194,
  [SMALL_STATE(22)] = 199,
  [SMALL_STATE(23)] = 206,
  [SMALL_STATE(24)] = 213,
  [SMALL_STATE(25)] = 218,
  [SMALL_STATE(26)] = 225,
  [SMALL_STATE(27)] = 230,
  [SMALL_STATE(28)] = 237,
  [SMALL_STATE(29)] = 244,
  [SMALL_STATE(30)] = 251,
  [SMALL_STATE(31)] = 256,
  [SMALL_STATE(32)] = 261,
  [SMALL_STATE(33)] = 268,
  [SMALL_STATE(34)] = 273,
  [SMALL_STATE(35)] = 278,
  [SMALL_STATE(36)] = 283,
  [SMALL_STATE(37)] = 287,
  [SMALL_STATE(38)] = 291,
  [SMALL_STATE(39)] = 295,
  [SMALL_STATE(40)] = 299,
  [SMALL_STATE(41)] = 303,
  [SMALL_STATE(42)] = 307,
  [SMALL_STATE(43)] = 311,
  [SMALL_STATE(44)] = 315,
  [SMALL_STATE(45)] = 319,
  [SMALL_STATE(46)] = 323,
  [SMALL_STATE(47)] = 327,
  [SMALL_STATE(48)] = 331,
  [SMALL_STATE(49)] = 335,
  [SMALL_STATE(50)] = 339,
  [SMALL_STATE(51)] = 343,
  [SMALL_STATE(52)] = 347,
  [SMALL_STATE(53)] = 351,
  [SMALL_STATE(54)] = 355,
  [SMALL_STATE(55)] = 359,
  [SMALL_STATE(56)] = 363,
  [SMALL_STATE(57)] = 367,
  [SMALL_STATE(58)] = 371,
  [SMALL_STATE(59)] = 375,
  [SMALL_STATE(60)] = 379,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [7] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_create_function_statement, 10),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [11] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_create_function_statement, 9),
  [13] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [15] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_create_function_statement, 8),
  [17] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_create_function_statement, 7),
  [19] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2),
  [21] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(9),
  [24] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_parameter, 2, .production_id = 1),
  [26] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [28] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [30] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [32] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__type, 3),
  [34] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [36] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_function_parameters_repeat1, 2), SHIFT_REPEAT(19),
  [39] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_function_parameters_repeat1, 2),
  [41] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [43] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [45] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [47] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [49] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [51] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [53] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_signature, 2),
  [55] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [57] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [59] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_parameters, 2),
  [61] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [63] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__statement, 2),
  [65] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [67] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [69] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [71] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dollar_quote, 3),
  [73] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_parameters, 3),
  [75] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [77] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [79] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_parameters, 4),
  [81] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dollar_quote, 2),
  [83] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [85] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [87] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [89] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [91] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [93] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [95] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [97] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_or_replace, 2),
  [99] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [101] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [103] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [105] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [107] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [109] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block, 2),
  [111] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [113] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_volatility, 1),
  [115] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [117] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [119] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [121] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [123] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [125] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_create_function_statement, 11),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_plpgsql(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .field_names = ts_field_names,
    .field_map_slices = ts_field_map_slices,
    .field_map_entries = ts_field_map_entries,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
