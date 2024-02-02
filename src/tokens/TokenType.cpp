#include "TokenType.hpp"

#include <map>
#include <string>

std::map<std::string, TokenType> TokenMap = {
    {"+", TokenType::PLUS},
    {"-", TokenType::MINUS},
    {"*", TokenType::STAR},
    {"/", TokenType::DIVIDE},
    {"%", TokenType::MODULO},
    {"!", TokenType::LOGICAL_NOT},
    {"&", TokenType::LOGICAL_AND},
    {"|", TokenType::LOGICAL_OR},
    {"=", TokenType::ASSIGNMENT},
    {">", TokenType::GREATER},
    {"<", TokenType::LESSER},
    {"(", TokenType::LEFT_PARENTHESIS},
    {")", TokenType::RIGHT_PARENTHESIS},
    {"[", TokenType::LEFT_BRACKET},
    {"]", TokenType::RIGHT_BRACKET},
    {"{", TokenType::LEFT_BRACE},
    {"}", TokenType::RIGHT_BRACE},
    {";", TokenType::SEMICOLON},
    {":", TokenType::COLON},
    {",", TokenType::COMMA},
    {"\'", TokenType::SINGLE_QUOTE},
    {"\"", TokenType::DOUBLE_QUOTE},
    {"\0", TokenType::EOF_TOKEN},

    {"!=", TokenType::BANG_EQUAL},
    {"==", TokenType::EQUAL_EQUAL},
    {">=", TokenType::GREATER_EQUAL},
    {"<=", TokenType::LESSER_EQUAL},
    {"+=", TokenType::PLUS_EQUAL},
    {"-=", TokenType::MINUS_EQUAL},
    {"++", TokenType::PLUS_PLUS},
    {"--", TokenType::MINUS_MINUS},

    {"define", TokenType::DEFINE},
};
