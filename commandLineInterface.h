#ifndef COMMAND_LINE_INTERFACE
#define COMMAND_LINE_INTERFACE

#include <string>

class CommandLineInterface {
	public:
		std::string getInput();
		std::string getNextWord(std::string &line);
		void printAdditionalArguments(std::string input);

		void toLower(std::string& input);

		/// <summary>Removes all commas, brackets and additional spaces in the passed string. Also converts all alphabetical characters to lowercase.</summary>
		/// <param name="input">Reference to the to be standardized string.</param>  
		void standardizeInputString(std::string& input);

		void handleHelpMessage(std::string input);
	private:
		const char* GENERAL_HELP_MESSAGE = "Acceptable commands are:\n -new\n -delete\n -sort\n -select\n -print\n -read\n -store\n -exit\nAcceptable surface types are:\n -circle\n -sector\n -polygon\nFor detailed help type 'help COMMAND_NAME'.";
		const char* NEW_HELP_MESSAGE = "new SURFACE_TYPE ID REST_ARGUMENTS\nThe new command adds a new surface of a given type. The user is able to choose all values including the id.";
		const char* DELETE_HELP_MESSAGE = "delete ID\nDeletes the surface with the given id if it exists.";
		const char* SORT_HELP_MESSAGE = "sort MODE\nSorts the selected surfaces either 'ascending or 'descending'.";
		const char* SELECT_HELP_MESSAGE = "select SURFACE_TYPE\nSelects only surfaces of a given type. If 'all' or no surface type is given selects all surfaces.";
		const char* PRINT_HELP_MESSAGE = "print MODE\nPrints an overview of all selected surfaces to the cmd if no mode is passed. The mode 'detailed' prints exact information of all and if an id is passed as mode only this surfaces is printed in detail.";
		const char* READ_HELP_MESSAGE = "read FILE_PATH...\nAdds all surfaces found in the file at given path to the current loaded and selected surfaces. Possible to enter multiple file paths.";
		const char* STORE_HELP_MESSAGE = "store FILE_PATH MODE\nStores surfaces to passed file path. If no path is given stores them to 'shapes.txt'. If no mode or 'selected' is passed stores only the selected surfaces. If 'all' is passed stores all.";
		const char* EXIT_HELP_MESSAGE = "exit\nCloses the program.";

		const char* CIRCLE_HELP_MESSAGE = "The syntax to create a circle looks like this:\n circle ID (CENTER_X, CENTER_Y) RADIUS\nBrackets and commas are optional.";
		const char* SECTOR_HELP_MESSAGE = "The syntax to create a sector looks like this:\n sector ID (CENTER_X, CENTER_Y) RADIUS (OPENING_POINT_X, OPENING_POINT_Y) APERTURE\nBrackets and commas are optional.";
		const char* POLYGON_HELP_MESSAGE = "The syntax to create a polygon looks like this:\n polygon ID (POINT1_X, POINT1_Y) (POINT2_X, POINT2_Y) (POINT3_X, POINT3_Y) ...\nAt least three points have to be passed. Brackets and commas are optional.";
};

#endif
