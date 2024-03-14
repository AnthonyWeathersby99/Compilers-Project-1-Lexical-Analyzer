#include "lexer.h"
#include <cctype>
#include <iostream>

Lexer::Lexer(const std::string &filename)
{
  file.open(filename);
  if (!file.is_open())
  {
    throw std::runtime_error("Could not open file");
  }
}

Token Lexer::getNextToken()
{
  char ch;
  std::string lexeme;

  // Skip whitespaces
  while (std::isspace(file.peek()))
    file.get();

  if (file.eof())
    return Token(TokenType::EndOfFile, "");

  file.get(ch);
  lexeme += ch;

  // Check for identifiers and keywords
  if (std::isalpha(ch) || ch == '_')
  {
    while (std::isalnum(file.peek()) || file.peek() == '_')
    {
      file.get(ch);
      lexeme += ch;
    }
    return Token(TokenType::Identifier, lexeme);
  }

  // Check for integer literals
  if (std::isdigit(ch))
  {
    while (std::isdigit(file.peek()))
    {
      file.get(ch);
      lexeme += ch;
    }
    return Token(TokenType::Integer, lexeme);
  }

  // Check for operators
  if (ch == '<' || ch == '>' || ch == '=' || ch == '!')
  {
    if (file.peek() == '=')
    {
      file.get(ch);
      lexeme += ch;
    }
    return Token(TokenType::Operator, lexeme);
  }

  // Check for separators
  if (ch == ';' || ch == ',' || ch == '(' || ch == ')')
  {
    return Token(TokenType::Separator, lexeme);
  }

  // If we reach this point, the character did not match any known token type
  return Token(TokenType::Unknown, lexeme);
}

Lexer::~Lexer()
{
  if (file.is_open())
  {
    file.close();
  }
}
