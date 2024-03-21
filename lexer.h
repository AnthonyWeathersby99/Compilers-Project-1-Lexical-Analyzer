#ifndef LEXER_H
#define LEXER_H

#include "token.h"
#include <fstream>
#include <string>

// The Lexer class is responsible for converting a stream of characters into a stream of tokens.
class Lexer
{
public:
  explicit Lexer(const std::string &filename); // Constructor that initializes the file stream.
  Token getNextToken();                        // Main method to extract the next token.

private:
  std::ifstream file; // File stream for reading input.
  char peekChar();    // Helper method to peek at the next character.
  char getChar();     // Helper method to get the next character.
  void ungetChar();   // Helper method to put back the last character read.
};

#endif // LEXER_H
