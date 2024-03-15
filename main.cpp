#include "lexer.h"
#include <iostream>
#include <fstream>

int main()
{
  try
  {
    Lexer lexer("input_scode.txt");
    std::ofstream outputFile("output.txt");

    if (!outputFile.is_open())
    {
      std::cerr << "Failed to open output.txt for writing.\n";
      return 1;
    }

    // Write headers to the outputFile.
    outputFile << "Token\t\tLexeme\n";

    // Process tokens until the end of file is reached.
    while (true)
    {
      Token token = lexer.getNextToken(); // Create a new Token object each iteration
      if (token.type == TokenType::EndOfFile)
        break;

      outputFile << token << std::endl;
    }

    outputFile.close();
  }
  catch (const std::exception &e)
  {
    std::cerr << "An error occurred: " << e.what() << std::endl;
    return 1;
  }

  return 0;
}
