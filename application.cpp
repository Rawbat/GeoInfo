#include "application.h"
#include <iostream>
#include <string>
#include "point.h"
#include "circle.h"
#include <fstream>

#define CIRCLE_ARGS 4

Application::Application() {
	quit_m = false;
}

void Application::run() {
	while (!quit_m) {
		std::cout << ">> ";
		std::string input = cli_m.getInput();

		std::string command = cli_m.getNextWord(input);

		if (command.compare("help") == 0) {
			cli_m.handleHelpMessage(input);
		}
		else if (command.compare("new") == 0) {
			createSurfaceOfString(input);
		}
		else if (command.compare("delete") == 0) {
			deleteSurfaceOfString(input);
		}
		else if (command.compare("print") == 0) {
			printSurfaces();
		}
		else if (command.compare("printDetailed") == 0) {
			printSurfacesDetailed();
		}
		else if (command.compare("read") == 0) {
			read(input);
		}
		else if (command.compare("exit") == 0) {
			quit_m = true;
		}
		else if (command.compare("") == 0) {
			
		}
		else {
			std::cout << "[ERROR] Command not found: " << "'" << command << "'" << std::endl;
		}
	}
	std::cout << "Goodbye!" << std::endl;
}

void Application::createSurfaceOfString(std::string input) {
	std::string type = cli_m.getNextWord(input);

	if (type.compare("circle") == 0) {
		int args[CIRCLE_ARGS];
		for (int i = 0; i < CIRCLE_ARGS; i++) {
			std::string arg_string = cli_m.getNextWord(input);
			if (arg_string.compare("") == 0) {
				std::cout << "[ERROR] Too few arguments." << std::endl;
				return;
			}
			else {
				try {
					args[i] = std::stoi(arg_string);
				}
				catch (std::invalid_argument const &e) {
					std::cout << "[ERROR] Invalid argument: " << "'" << arg_string << "'." << " Expected Integer" << std::endl;
					return;
				}
				catch (std::out_of_range const &e) {
					std::cout << "[ERROR] Number too big: " << "'" << arg_string << "'" << std::endl;
					return;
				}
			}
		}

		//Check if the user added more arguments than neccessary
		
		cli_m.printAdditionalArguments(input);

		if (idExists(args[0])) {
			return;
		}

		

		surfaces_m.push_back(new Circle(args[0], Point(args[1], args[2]), args[3]));
	}
}


void Application::deleteSurfaceOfString(std::string input) {
	std::string id_string = cli_m.getNextWord(input);
	int id;

	try {
		id = std::stoi(id_string);
	}
	catch (std::invalid_argument const &e) {
		std::cout << "[ERROR] Invalid argument: " << "'" << id_string << "'." << " Expected Integer" << std::endl;
		return;
	}
	catch (std::out_of_range const &e) {
		std::cout << "[ERROR] Number too big: " << "'" << id_string << "'" << std::endl;
		return;
	}

	for (std::vector<Surface*>::iterator it = surfaces_m.begin(); it != surfaces_m.end(); it++) {
		if ((*it)->getId() == id) {
			std::cout << "Following surface has been deleted:" << std::endl << **it << std::endl;
			delete *it;
			surfaces_m.erase(it);
			return;
		}
	}
	std::cout << "[ERROR] ID does not exist: " << "'" << id << "'" << std::endl;
}

bool Application::idExists(int id) {
	for (Surface *surface : surfaces_m) {
		if (surface->getId() == id) {
			std::cout << "[ERROR] ID already existing: " << "'" << id << "'" << std::endl;
			return true;
		}
	}
	return false;
}

void Application::read(std::string input) {
	std::string file_path = cli_m.getNextWord(input);

	std::cout << file_path << std::endl;

	cli_m.printAdditionalArguments(input);
}

void Application::store(std::vector<Surface*> surfaces) {

}


void Application::printSurfaces() {
	for (Surface *surface : surfaces_m) {
		std::cout << surface->getName() << " " << surface->getId() << std::endl;
	}
}

void Application::printSurfacesDetailed() {
	for (Surface *surface : surfaces_m) {
		std::cout << *surface << std::endl;
	}
}
