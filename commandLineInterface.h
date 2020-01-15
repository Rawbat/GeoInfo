/*
Projekt: Flächenhafte Objekte
Authors: Patrick Ablinger, Robert Leiner
*/

#ifndef COMMAND_LINE_INTERFACE
#define COMMAND_LINE_INTERFACE

#include <string>

/// <summary>A class containing multiple helper methods to gather and process command line input</summary>
class CommandLineInterface {
	public:
      /// <summary>Waits for the next input line in the cmd and returns it as a string</summary>
      /// <returns>The read string from the cmd</returns> 
		static std::string getInput();

      /// <summary>Takes a string as an argument removes the first word from it(everything up to the first space) and returns this word as a string.</summary>
      /// <param name="line">Reference to the string of which the first word is going to be returned. This word is also removed from the passed string.</param>  
      /// <returns>The first word of the passed string. That means everything up to the first space of the passed string.</returns> 
      static std::string getNextWord(std::string &line);
		
      /// <summary>Takes a string as an argument and converts all alphabetical characters to lowercase</summary>
      /// <param name="line">Reference to the string of which all alphabetical characters are converted to lowercase</param>  
      static void toLower(std::string& input);

		/// <summary>Removes all commas, brackets and additional spaces in the passed string. Also converts all alphabetical characters to lowercase.</summary>
		/// <param name="input">Reference to the to be standardized string.</param>  
      static void standardizeInputString(std::string& input);

      /// <summary>Takes a string as an argument and prints all contained words as an additional argument warning</summary>
      /// <param name="input">The string containing the additional arguments</param> 
      static void printAdditionalArguments(std::string input);

      /// <summary>Takes a string as an argument and prints the help message corresponding to the argument</summary>
      /// <param name="input">The string containing the help arguments</param> 
      static void handleHelpMessage(std::string input);
	private:

      //Constant help messages
      static const char* GENERAL_HELP_MESSAGE;
      static const char* NEW_HELP_MESSAGE;
      static const char* DELETE_HELP_MESSAGE;
      static const char* SORT_HELP_MESSAGE;
      static const char* SELECT_HELP_MESSAGE;
      static const char* PRINT_HELP_MESSAGE;
      static const char* READ_HELP_MESSAGE;
      static const char* STORE_HELP_MESSAGE;
      static const char* EXIT_HELP_MESSAGE;

      static const char* CIRCLE_HELP_MESSAGE;
      static const char* SECTOR_HELP_MESSAGE;
      static const char* POLYGON_HELP_MESSAGE;
};

#endif
