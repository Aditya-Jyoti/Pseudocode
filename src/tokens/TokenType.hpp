#ifndef TOKEN_TYPES
#define TOKEN_TYPES

#include <map>
#include <string>

enum TokenType {
  // keywords
  IF,
  ELSE_IF,
  ELSE,
  FOR,
  WHILE,
  BREAK,
  CONTINUE,
  DEFINE,
  EQUAL,
  AND,
  OR,
  NOT,
  EACH,
  FROM,
  IS,
  WITH,
  IN,
  BETWEEN,
  TRUE,
  FALSE,
  RETURN,
  CLASS,
  SELF,
  FUNCTION,
  NONE,
  DISPLAY,
  DO,
  END,
  IMPORT,

  // literals
  IDENTIFIER,
  STRING,
  NUMBER,
  INTEGER,
  DECIMAL,
  BOOLEAN,
  ARRAY,
  MAP,

  // arithmetic
  PLUS,
  MINUS,
  STAR,
  DIVIDE,
  MODULO,

  // comparision
  BANG_EQUAL,
  EQUAL_EQUAL,
  GREATER,
  GREATER_EQUAL,
  LESSER,
  LESSER_EQUAL,

  // boolean logic
  LOGICAL_AND,
  LOGICAL_OR,
  LOGICAL_NOT,

  // assignment
  ASSIGNMENT,
  PLUS_EQUAL,
  MINUS_EQUAL,
  PLUS_PLUS,
  MINUS_MINUS,

  // single char tokens
  LEFT_PARENTHESIS,
  RIGHT_PARENTHESIS,
  LEFT_BRACE,
  RIGHT_BRACE,
  LEFT_BRACKET,
  RIGHT_BRACKET,
  SINGLE_QUOTE,
  DOUBLE_QUOTE,
  SEMICOLON,
  COLON,
  COMMA,
  DOT,

  // extra
  EOF_TOKEN,
  ILLEGAL,
  UNDEFINED
};

extern std::map<std::string, TokenType> TokenMap;

#endif
