#ifndef TOKEN_H
#define TOKEN_H

#include <iostream>
#include <string>

enum class TokenType
{
  Keyword,
  Integer,
  Real,
  Identifier,
  Operator,
  Separator,
  EndOfFile,
  Unknown
};

std::string tokenTypeToString(TokenType type);

struct Token
{
  TokenType type;
  std::string lexeme;

  Token(TokenType type, std::string lexeme) : type(type), lexeme(std::move(lexeme)) {}
};

std::ostream &operator<<(std::ostream &out, const Token &token);

#endif // TOKEN_H
