#ifndef LEXER_H
#define LEXER_H

#include "token.h"
#include <fstream>
#include <string>

class Lexer
{
public:
  explicit Lexer(const std::string &filename);
  ~Lexer();
  Token getNextToken();

private:
  std::ifstream file;
  char peekChar();
  char getChar();
  void ungetChar();
};

#endif // LEXER_H
