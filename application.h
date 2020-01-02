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
		void store();
		void read();
		void deleteSurface(Surface *surface);
		void createSurfaceOfString(std::string input);
		void deleteSurfaceOfString(std::string input);

		CommandLineInterface cli_m;

		std::vector<Surface*> surfaces_m;
		
};

#endif
