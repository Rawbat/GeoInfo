/*
Projekt: Flächenhafte Objekte
Authors: Patrick Ablinger, Robert Leiner
*/

#ifndef APPLICATION_H
#define APPLICATION_H

#include <vector>
#include "surface.h"
#include "commandLineInterface.h"
#include <unordered_map>
#include <stdexcept>

/// <summary>A command line application to read, create, display and store different types of geometry. Call run to start it.</summary>
class Application {
	public:
      //Constructor
	   Application();

		/// <summary>The main loop of the application. Calls helper functions to gather input and process it.</summary>
		void run();	
		
	private:
      /// <summary>If false the main loop stops. Set to false by the exit command.</summary>
		bool quit_m;

      /// <summary>All loaded surfaces</summary>
		std::vector<Surface*> surfaces_m;

      /// <summary>The currently selected surfaces. Subset of all loaded surfaces.</summary>
		std::vector<Surface*> selected_surfaces_m;

		/// <summary>Executes the first word of the passed string as a command.</summary>
		/// <param name="input">The input containing the first word as the command and possibly additional words as arguments.</param>  
		void executeCommand(std::string input);

		/// <summary>Checks all surfaces if the passed id already exists in one of them and prints a warning if it does.</summary>
		/// <param name="id">The id to checked against.</param>  
		/// <returns>Boolean true if the id already exists; False if not.</returns> 
		bool idExists(int id);

		/// <summary>Creates and adds a surface to the surfaces vector. Resets all prior chosen selections. If a surface with the same id already exists does not create the surface.</summary>
		/// <param name="input">A string containing the type of the surface as the first word the id as the second and possible arguments as additional words.</param>  
		void createSurfaceOfString(std::string input);

		/// <summary>Removes a surface of a specific id from the surfaces vector and deletes it. If the id does not exist throws an invalid_argument exception.</summary>
		/// <param name="input">A string containing the id as the first word.</param>  
		void deleteSurfaceOfString(std::string input);

		/// <summary>Sorts the currently selected surfaces either ascending or descending.</summary>
		/// <param name="input">A string containing the type of sorting as the first word.</param>  
		void sortSurfaces(std::string input);

		/// <summary>Selects a specific type of surface or resets the current selection</summary>
		/// <param name="input">A string containing the type of surface or 'all' if the selection is to be reset.</param>  
		void selectSurfaces(std::string input);

		/// <summary>Reads one or more files, creates surfaces out of the file information and adds them to the surface vector.</summary>
		/// <param name="input">A string containing one or more file paths.</param>  
		void read(std::string input);

		/// <summary>Stores either the selected surfaces or all surfaces to a file.</summary>
		/// <param name="input">A string containing a file path and the store type. If no file path is passed defaults to 'shapes.txt'.</param> 
		void store(std::string input);

		/// <summary>Prints the selected surfaces or a specific surface to the console.</summary>
		/// <param name="input">A string containing the print mode. Either simple, detailed or specific id printing.</param> 
		void printSurfaces(std::string input);

		/// <summary>Prints a single surface specified by an id to the console.</summary>
		/// <param name="input">A string containing the surface id as the first word. If id does not exist throws and invalid_argument exception.</param> 
		void printSingleSurface(std::string input);

		/// <summary>Prints the selected surfaces to the console in detail.</summary>
		void printSurfacesDetailed();
};

#endif
