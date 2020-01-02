#include "application.h"
#include <iostream>
#include <string>
#include "point.h"
#include "circle.h"

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
			cli_m.printHelpMessage();
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
		else if (command.compare("") == 0) {
			
		}
		else {
			std::cout << "[ERROR] Command not found: " << "'" << command << "'" << std::endl;
		}
		

		/*try {
			command_handler_m.handle(input);
		}
		catch (std::exception &e) {

		}*/
	}
}

void Application::createSurfaceOfString(std::string input) {
	std::string type = cli_m.getNextWord(input);

	if (type.compare("circle") == 0) {
		int args[CIRCLE_ARGS];
		for (int i = 0; i < CIRCLE_ARGS; i++) {
			std::string arg_string = cli_m.getNextWord(input);
			if (arg_string.compare("") == 0) {
				std::cout << "[Error] Too few arguments." << std::endl;
				return;
			}
			else {
				try {
					args[i] = std::stoi(arg_string);
				}
				catch (std::invalid_argument const &e) {
					std::cout << "[Error] Invalid argument: " << "'" << arg_string << "'." << " Expected Integer" << std::endl;
					return;
				}
				catch (std::out_of_range const &e) {
					std::cout << "[Error] Number too big: " << "'" << arg_string << "'" << std::endl;
					return;
				}
			}
		}

		//Check if the user added more arguments than neccessary
		std::string additional_arg = cli_m.getNextWord(input);
		if (additional_arg.compare("") != 0) {
			std::cout << "[Warning] Following arguments have not been used: ";

			while (additional_arg.compare("") != 0) {
				std::cout << "'" << additional_arg << "'" << " ";
				additional_arg = cli_m.getNextWord(input);
			}

			std::cout << std::endl;
		}

		for (Surface *surface : surfaces_m) {
			if (surface->getId() == args[0]) {
				std::cout << "[Error] Id already existing: " << "'" << args[0] << "'" << std::endl;
				return;
			}
		}

		surfaces_m.push_back(new Circle(args[0], Point(args[1], args[2]), args[3]));
	}
}


void Application::deleteSurfaceOfString(std::string input) {

}

void Application::printSurfaces() {
	for (Surface *surface : surfaces_m) {
		std::cout << *surface << std::endl;
	}
}
