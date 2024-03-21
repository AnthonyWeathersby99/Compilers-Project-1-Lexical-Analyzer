#include "lexer.h"
#include <cctype>
#include <stdexcept>

// Constructor: Opens file for lexical analysis.
Lexer::Lexer(const std::string &filename)
{
  file.open(filename);
  if (!file.is_open())
  {
    throw std::runtime_error("Could not open file");
  }
}


// Return next character in file w/o consuming it
char Lexer::peekChar()
{
  return static_cast<char>(file.peek());
}

// Consumes and returns next character in file
char Lexer::getChar()
{
  return static_cast<char>(file.get());
}

// Puts last read character back into the file stream
void Lexer::ungetChar()
{
  file.unget();
}

// Returns next token from input file
Token Lexer::getNextToken()
{
  char ch;
  std::string lexeme;

  // Skip whitespace characters
  while (std::isspace(peekChar()))
    getChar();

  // End of file is reached, return EOF token
  if (file.eof())
    return Token(TokenType::EndOfFile, "");

  ch = getChar();
  lexeme = ch;

  // If character is a letter or underscore, can be an identifier or keyword
  if (std::isalpha(ch) || ch == '_')
  {
    while (std::isalnum(peekChar()) || peekChar() == '_')
    {
      lexeme += getChar();
    }
    if (lexeme == "while" /* selected keyword, || lexeme == 'another keyword' */)
    {
      return Token(TokenType::Keyword, lexeme);
    }
    return Token(TokenType::Identifier, lexeme);
  }

  // If character is digit, could be integer or real number
  if (std::isdigit(ch))
  {
    bool hasDecimal = false;
    while (std::isdigit(peekChar()) || (!hasDecimal && peekChar() == '.'))
    {
      if (peekChar() == '.')
      {
        hasDecimal = true; // Decimal==real number
      }
      lexeme += getChar();
    }
    return Token(hasDecimal ? TokenType::Real : TokenType::Integer, lexeme);
  }

  // Operators
  if (ch == '<' || ch == '>' || ch == '=' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
  {
    return Token(TokenType::Operator, lexeme);
  }

  // Separators
  if (ch == ';' || ch == '(' || ch == ')')
  {
    return Token(TokenType::Separator, lexeme);
  }

  // Unknown tokens
  return Token(TokenType::Unknown, lexeme);
}
