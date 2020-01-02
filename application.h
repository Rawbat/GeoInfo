#ifndef APPLICATION_H
#define APPLICATION_H

#include <vector>
#include "surface.h"
#include "commandLineInterface.h"

class Application {
	public:
		Application();
		void run();	
		
	private:
		bool quit_m;
		void read(std::string input);
		void store(std::vector<Surface*> surfaces, std::string input);
		void deleteSurface(Surface *surface);
		void createSurfaceOfString(std::string input);
		void deleteSurfaceOfString(std::string input);


		bool idExists(int id);

		void printSurfaces();
		void printSurfacesDetailed();
		

		CommandLineInterface cli_m;

		std::vector<Surface*> surfaces_m;
		
};

#endif
