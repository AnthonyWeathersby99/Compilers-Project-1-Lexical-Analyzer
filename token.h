#ifndef TOKEN_H
#define TOKEN_H

#include <iostream>
#include <string>

// Defines the different types of tokens for lexer
enum class TokenType
{
  Keyword,    // Language keywords, currently only 'while'
  Integer,    // Integer literals
  Real,       // Real (floating-point) literals
  Identifier, // Identifiers such as variable names, currently 'upper'
  Operator,   // '+', '-', '*', '/', '<', '>', '='
  Separator,  // ';', '(', ')'
  EndOfFile,  // Special token indicating the end of the file reached
  Unknown     // No matching token
};

// Converts TokenType to a string
std::string tokenTypeToString(TokenType type);

// Represents a token, with a type and the actual text (lexeme) from the source code
struct Token
{
  TokenType type;     // The type of token
  std::string lexeme; // The text of token

  // Constructor for creating a Token with a given type and lexeme
  Token(TokenType type, std::string lexeme) : type(type), lexeme(std::move(lexeme)) {}
};

// Overload stream insertion operator to output token's details to an output stream
std::ostream &operator<<(std::ostream &out, const Token &token);

#endif
