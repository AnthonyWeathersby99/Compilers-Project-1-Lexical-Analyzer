#include "token.h"

// Output stream operator implementation
std::ostream &operator<<(std::ostream &os, const TokenType &type)
{
  switch (type)
  {
  case TokenType::Integer:
    return os << "Integer";
  case TokenType::Identifier:
    return os << "Identifier";
  case TokenType::Operator:
    return os << "Operator";
  case TokenType::Separator:
    return os << "Separator";
  case TokenType::EndOfFile:
    return os << "EndOfFile";
  case TokenType::Unknown:
    return os << "Unknown";
  default:
    return os << "UnknownTokenType";
  }
}
