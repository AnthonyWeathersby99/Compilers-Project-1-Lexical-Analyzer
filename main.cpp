#include "lexer.h"
#include <iostream>
#include <fstream>

// The main function serves as the entry point for the program.
int main()
{
  try
  {
    // Create a Lexer object for the input file.
    Lexer lexer("input_scode.txt");
    // Prepare the output file for writing tokens.
    std::ofstream outputFile("output.txt");

    // Check if the output file was successfully opened.
    if (!outputFile.is_open())
    {
      std::cerr << "Failed to open output.txt for writing.\n";
      return 1; // Exit with error code 1 if the file could not be opened.
    }

    // Write the header to the output file.
    outputFile << "Token\t\tLexeme\n";

    // Loop to process each token until the end of file is reached.
    while (true)
    {
      // Create a new Token object each iteration.
      Token token = lexer.getNextToken();
      // Break the loop if the EndOfFile token is encountered.
      if (token.type == TokenType::EndOfFile)
        break;

      // Write the token and its lexeme to the output file.
      outputFile << token << std::endl;
    }

    // Close the output file after writing all tokens.
    outputFile.close();
  }
  catch (const std::exception &e)
  {
    // If an error occurs, print the error message to standard error.
    std::cerr << "An error occurred: " << e.what() << std::endl;
    return 1; // Exit with error code 1 if an exception is thrown.
  }

  // Return 0 to indicate success.
  return 0;
}
