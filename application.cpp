#include "application.h"
#include <iostream>
#include <string>
#include "point.h"
#include "circle.h"
#include <fstream>
#include "circleSector.h"
#include "polygon.h"

#define CIRCLE_ARGS 4
#define SECTOR_ARGS 7
#define POLYGON_ARGS 100000

Application::Application() {
	quit_m = false;
}

void Application::run() {
	while (!quit_m) {
		std::cout << ">> ";
		std::string input = cli_m.getInput();

		standardizeInputString(input);

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
		else if (command.compare("printdetailed") == 0) {
			printSurfacesDetailed();
		}
		else if (command.compare("read") == 0) {
			read(input);
		}
		else if (command.compare("store") == 0) {
			store(surfaces_m, input);
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

	std::vector<double> args;
	int arg_number = 0;

	if (type.compare("circle") == 0) {
		arg_number = CIRCLE_ARGS;
	}
	else if (type.compare("sector") == 0) {
		arg_number = SECTOR_ARGS;
	}
	else if (type.compare("polygon") == 0) {
		arg_number = POLYGON_ARGS;
	}
	else {
		std::cout << "[ERROR] Unknown surface type: " << type << std::endl;
		return;
	}

	for (int i = 0; i < arg_number; i++) {
		std::string arg_string = cli_m.getNextWord(input);
		if (arg_string.compare("") == 0) {
			//Because a polygon theortically is able to have infinite edges an exception has to be made for this cause
			//TODO check if the last point contains both x and y coordinates in a polygon
			if (type.compare("polygon") == 0) {
				break;
			}
			else {
				std::cout << "[ERROR] Too few arguments." << std::endl;
				return;
			}
		}
		else {
			try {
				args.push_back(std::stod(arg_string));
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

	int id = static_cast<int>(args.at(0));

	if (!idExists(id)) {
		if (type.compare("circle") == 0) {
			surfaces_m.push_back(new Circle(id, Point(args.at(1), args.at(2)), args.at(3)));
		}
		else if (type.compare("sector") == 0) {
			surfaces_m.push_back(new CircleSector(id, Point(args.at(1), args.at(2)), args.at(3), Point(args.at(4), args.at(5)), args.at(6)));
		}
		else if (type.compare("polygon") == 0) {
			std::vector<Point> points;
			for (int i = 1; i < args.size() - 1; i += 2) {
				points.push_back(Point(args.at(i), args.at(i + 1)));
			}
			surfaces_m.push_back(new Polygon(id, points));
		}
	}

	

	
		

}

void Application::standardizeInputString(std::string& input) {
	int c = 0;

	while(c < input.size()) {
		//Remove additional spaces
		if (c < input.size() - 1 && input.at(c) == ' ' && input.at(c + 1) == ' ') {
			input.erase(c, 1);
		}
		else if (input.at(c) == '\t') {
			input.replace(c, 1, " ");
			if (c > 0) {
				c--;
			}
		}
		//Remove all commas
		else if (input.at(c) == ',') {
			input.replace(c, 1, " ");
			if (c > 0) {
				c--;
			}
		}
		//Remove all parentheses
		else if (input.at(c) == '(' || input.at(c) == ')') {
			input.replace(c, 1, " ");
			if (c > 0) {
				c--;
			}
		}
		//Convert everything to lowercase
		else if (input.at(c) >= 'A' && input.at(c) <= 'Z') {
			input.replace(c, 1, std::string(1, static_cast<char>(input.at(c) - ('A' - 'a'))));
		}
		else {
			c++;
		}
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

	cli_m.printAdditionalArguments(input);

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

	if (file_path.compare("") == 0) {
		std::cout << "[ERROR] No file specified to read from." << std::endl;
	}

	while (file_path.compare("") != 0) {
		std::ifstream file(file_path.c_str());
		if (file.is_open()) {
			std::string line;
			while (std::getline(file, line)) {
				standardizeInputString(line);
				createSurfaceOfString(line);
			}
			file.close();
		}
		else {
			std::cout << "[ERROR] Could not open file at relative path: " << file_path << std::endl;
		}
		file_path = cli_m.getNextWord(input);
	}

	

	cli_m.printAdditionalArguments(input);
}

void Application::store(std::vector<Surface*> surfaces, std::string input) {
	std::string file_path = cli_m.getNextWord(input);
	if (file_path.compare("") == 0) {
		std::cout << "[NOTIFICATION] No file path passed. Content is stored to standard file 'shapes.txt'." << std::endl;
		file_path = "shapes.txt";
	}

	std::ofstream file(file_path.c_str());
	if (file.is_open()) {
		for (Surface* surface : surfaces) {
			file << *surface << std::endl;
		}
		file.close();
	}
	else {
		std::cout <<  "[ERROR] Could not open file at relative path: " << file_path << std::endl;
	}
	cli_m.printAdditionalArguments(input);
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
