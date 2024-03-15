#include "token.h"

std::string tokenTypeToString(TokenType type)
{
  switch (type)
  {
  case TokenType::Keyword:
    return "Keyword";
  case TokenType::Integer:
    return "Integer";
  case TokenType::Real:
    return "Real";
  case TokenType::Identifier:
    return "Identifier";
  case TokenType::Operator:
    return "Operator";
  case TokenType::Separator:
    return "Separator";
  case TokenType::EndOfFile:
    return "EndOfFile";
  case TokenType::Unknown:
    return "Unknown";
  default:
    return "UnknownTokenType";
  }
}

std::ostream &operator<<(std::ostream &out, const Token &token)
{
  out << tokenTypeToString(token.type) << " " << token.lexeme;
  return out;
}
