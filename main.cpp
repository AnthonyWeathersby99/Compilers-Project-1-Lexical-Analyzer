#include "lexer.h"
#include <iostream>
#include <fstream>

int main()
{
  Lexer lexer("input_scode.txt");
  std::ofstream outputFile("output.txt");

  while (true)
  {
    Token token = lexer.getNextToken();
    if (token.type == TokenType::EndOfFile)
      break;

    outputFile << token.type << " " << token.lexeme << std::endl;
  }

  outputFile.close();
  return 0;
}
