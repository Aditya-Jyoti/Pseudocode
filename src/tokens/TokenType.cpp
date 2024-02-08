#include "TokenType.hpp"

#include <map>
#include <string>

std::map<std::string, TokenType> SingleCharacterMap = {
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
    {".", TokenType::DOT},
    {"\'", TokenType::SINGLE_QUOTE},
    {"\"", TokenType::DOUBLE_QUOTE},
    {"\0", TokenType::EOF_TOKEN},
};

std::map<std::string, TokenType> DoubleCharacterMap = {
    {"!=", TokenType::BANG_EQUAL},    {"==", TokenType::EQUAL_EQUAL},
    {">=", TokenType::GREATER_EQUAL}, {"<=", TokenType::LESSER_EQUAL},
    {"+=", TokenType::PLUS_EQUAL},    {"-=", TokenType::MINUS_EQUAL},
    {"++", TokenType::PLUS_PLUS},     {"--", TokenType::MINUS_MINUS},
};

std::map<std::string, TokenType> MultipleCharacterMap = {
    {"define", TokenType::DEFINE},
    {"if", TokenType::IF},
    {"else", TokenType::ELSE},
    {"for", TokenType::FOR},
    {"while", TokenType::WHILE},
    {"break", TokenType::BREAK},
    {"continue", TokenType::CONTINUE},
    {"and", TokenType::AND},
    {"or", TokenType::OR},
    {"not", TokenType::NOT},
    {"each", TokenType::EACH},
    {"from", TokenType::FROM},
    {"is", TokenType::IS},
    {"with", TokenType::WITH},
    {"in", TokenType::IN},
    {"between", TokenType::BETWEEN},
    {"return", TokenType::RETURN},
    {"true", TokenType::TRUE},
    {"false", TokenType::FALSE},
    {"class", TokenType::CLASS},
    {"self", TokenType::SELF},
    {"function", TokenType::FUNCTION},
    {"none", TokenType::NONE},
    {"do", TokenType::DO},
    {"end", TokenType::END},
    {"import", TokenType::IMPORT},
};
