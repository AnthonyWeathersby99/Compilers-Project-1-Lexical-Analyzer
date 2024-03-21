#include "token.h"

// Converts the TokenType enum to a human-readable string for printing.
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

// Overloads the << operator to make Tokens printable to standard streams such as std::cout.
std::ostream &operator<<(std::ostream &out, const Token &token)
{
  // Use the tokenTypeToString function to get the string representation of the token type.
  out << tokenTypeToString(token.type) << " " << token.lexeme;
  return out;
}
