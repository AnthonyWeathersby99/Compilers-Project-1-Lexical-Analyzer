#include "lexer.h"
#include <cctype>
#include <stdexcept>

Lexer::Lexer(const std::string &filename)
{
  file.open(filename);
  if (!file.is_open())
  {
    throw std::runtime_error("Could not open file");
  }
}

Lexer::~Lexer()
{
  if (file.is_open())
  {
    file.close();
  }
}

char Lexer::peekChar()
{
  return static_cast<char>(file.peek());
}

char Lexer::getChar()
{
  return static_cast<char>(file.get());
}

void Lexer::ungetChar()
{
  file.unget();
}

Token Lexer::getNextToken()
{
  char ch;
  std::string lexeme;

  // Skip whitespace
  while (std::isspace(peekChar()))
    getChar();

  if (file.eof())
    return Token(TokenType::EndOfFile, "");

  ch = getChar();
  lexeme = ch;

  // Handle identifiers and keywords
  if (std::isalpha(ch) || ch == '_')
  {
    while (std::isalnum(peekChar()) || peekChar() == '_')
    {
      lexeme += getChar();
    }
    // Check if the identifier is a keyword.
    if (lexeme == "while" /* add other keywords as necessary */)
    {
      return Token(TokenType::Keyword, lexeme);
    }
    return Token(TokenType::Identifier, lexeme);
  }

  // Handle numeric literals (integers and reals)
  if (std::isdigit(ch))
  {
    bool hasDecimal = false;
    while (std::isdigit(peekChar()) || (!hasDecimal && peekChar() == '.'))
    {
      if (peekChar() == '.')
      {
        hasDecimal = true; // Record that we've seen a decimal point
      }
      lexeme += getChar();
    }
    // Since we're treating all numbers as Reals, no need for a condition here
    return Token(TokenType::Real, lexeme);
  }

  // Handle operators
  if (ch == '<' || ch == '>' || ch == '=' || ch == '+' /* add other operators */)
  {
    return Token(TokenType::Operator, lexeme);
  }

  // Handle separators
  if (ch == ';' || ch == '(' || ch == ')' /* add other separators */)
  {
    return Token(TokenType::Separator, lexeme);
  }

  return Token(TokenType::Unknown, lexeme);
}
