#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include <iostream>

// Token types
enum class TokenType
{
  Integer,
  Identifier,
  Operator,
  Separator,
  EndOfFile,
  Unknown
};

struct Token
{
  TokenType type;
  std::string lexeme;

  Token(TokenType t, std::string lex) : type(t), lexeme(std::move(lex)) {}
};
std::ostream &operator<<(std::ostream &os, const TokenType &type);

#endif // TOKEN_H
