#ifndef APPLICATION_H
#define APPLICATION_H

#include <vector>
#include "surface.h"
#include "commandLineInterface.h"
#include <unordered_map>

class Application {
	public:
		Application();
		void run();	
		
	private:

		bool quit_m;
		void read(std::string input);
		void store(std::string input);
		void deleteSurface(Surface *surface);
		void createSurfaceOfString(std::string input);
		void deleteSurfaceOfString(std::string input);
		void standardizeInputString(std::string& input);
		void executeCommand(std::string input);

		void selectSurfaces(std::string input);
		void sortSurfaces(std::string input);


		bool idExists(int id);

		void printSurfaces(std::string input);
		void printSingleSurface(std::string input);
		void printSurfacesDetailed();
		

		CommandLineInterface cli_m;

		std::vector<Surface*> surfaces_m;
		std::vector<Surface*> selected_surfaces_m;
		
};

#endif
