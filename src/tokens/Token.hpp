#ifndef TOKENS
#define TOKENS

#include "TokenType.hpp"

#include <string>

struct Token {
  TokenType type = TokenType::UNDEFINED;
  std::string literal = "";

  Token() = default;
  Token(std::string literal, TokenType type) : literal(literal), type(type) {}

  bool isEmpty() {
    return this->type == TokenType::UNDEFINED && this->literal == "";
  };

  bool operator==(const Token &RHS) const {
    return this->type == RHS.type && this->literal == RHS.literal;
  }
};

#endif
