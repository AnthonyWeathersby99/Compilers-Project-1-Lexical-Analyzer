#ifndef LEXER_H
#define LEXER_H

#include "token.h"
#include <string>
#include <fstream>
#include <vector>

class Lexer
{
public:
  explicit Lexer(const std::string &filename);
  Token getNextToken();

private:
  std::ifstream file;
  // You can add more private methods or member variables as needed.
};

#endif // LEXER_H
