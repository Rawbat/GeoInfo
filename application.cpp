#include "application.h"
#include <iostream>
#include <string>
#include "point.h"
#include "circle.h"
#include <fstream>
#include "circleSector.h"
#include "polygon.h"
#include <algorithm>

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

		try {
			executeCommand(input);
		}
		catch (std::invalid_argument& const e) {
			std::cout << e.what() << std::endl;
		}
		catch (std::out_of_range& const e) {
			std::cout << e.what() << std::endl;
		}
		
	}
	std::cout << "Goodbye!" << std::endl;
}

void Application::executeCommand(std::string input) {

	std::string command = cli_m.getNextWord(input);

	try {
		if (command.compare("help") == 0) {
			cli_m.handleHelpMessage(input);
		}
		else if (command.compare("new") == 0) {
			createSurfaceOfString(input);
		}
		else if (command.compare("delete") == 0) {
			deleteSurfaceOfString(input);
		}
		else if (command.compare("sort") == 0) {
			sortSurfaces(input);
		}
		else if (command.compare("select") == 0) {
			selectSurfaces(input);
		}
		else if (command.compare("print") == 0) {
			printSurfaces(input);
		}
		else if (command.compare("read") == 0) {
			read(input);
		}
		else if (command.compare("store") == 0) {
			store(input);
		}
		else if (command.compare("exit") == 0) {
			quit_m = true;
		}
		else if (command.compare("") == 0) {

		}
		else {
			throw std::invalid_argument("[ERROR] Command not found: '" + command + "'.");
		}
	}
	catch (std::invalid_argument& const e) {
		throw e;
	}
	catch (std::out_of_range& const e) {
		throw e;
	}
	
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
		throw std::invalid_argument("[ERROR] Unknown surface type: '" + type + "'.");
	}

	for (int i = 0; i < arg_number; i++) {
		std::string arg_string = cli_m.getNextWord(input);
		if (arg_string.compare("") == 0) {
			//Because a polygon theortically is able to have infinite edges an exception has to be made for this cause
			if (type.compare("polygon") == 0) {
				if ((i % 2) == 0) {
					throw std::invalid_argument("[ERROR] Last point in polygon is missing y argument.");
				}
				break;
			}
			else {
				throw std::invalid_argument("[ERROR] Too few arguments.");
			}
		}
		else {
			try {
				args.push_back(std::stod(arg_string));
			}
			catch (std::invalid_argument) {
				throw std::invalid_argument("[ERROR] Invalid argument: '" + arg_string + "'. Expected Integer.");
			}
			catch (std::out_of_range) {
				throw std::out_of_range("ERROR] Number too big: '" + arg_string + "'.");
			}
		}
	}

	//Check if the user added more arguments than neccessary
	cli_m.printAdditionalArguments(input);

	int id = static_cast<int>(args.at(0));

	try {
		if (!idExists(id)) {
			if (type.compare("circle") == 0) {
				Circle* temp_circle = new Circle(id, Point(args.at(1), args.at(2)), args.at(3));
				surfaces_m.push_back(temp_circle);
				selected_surfaces_m.push_back(temp_circle);
			}
			else if (type.compare("sector") == 0) {
				CircleSector* temp_sector = new CircleSector(id, Point(args.at(1), args.at(2)), args.at(3), Point(args.at(4), args.at(5)), args.at(6));
				surfaces_m.push_back(temp_sector);
				selected_surfaces_m.push_back(temp_sector);
			}
			else if (type.compare("polygon") == 0) {
				std::vector<Point> points;
				for (unsigned int i = 1; i < args.size() - 1; i += 2) {
					points.push_back(Point(args.at(i), args.at(i + 1)));
				}
				Polygon* temp_polygon = new Polygon(id, points);
				surfaces_m.push_back(temp_polygon);
				selected_surfaces_m.push_back(temp_polygon);
			}
			selected_surfaces_m = surfaces_m;
		}
	}
	catch (std::invalid_argument& e) {
		throw e;
	}

	
}

void Application::standardizeInputString(std::string& input) {

	//Convert everything to lowercase
	cli_m.toLower(input);

	unsigned int c = 0;
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
	catch (std::invalid_argument) {
		throw std::invalid_argument("[ERROR] Invalid argument: '" + id_string + "'. Expected Integer.");
	}
	catch (std::out_of_range) {
		throw std::out_of_range("ERROR] Number too big: '" + id_string + "'.");
	}

	cli_m.printAdditionalArguments(input);

	for (std::vector<Surface*>::iterator it = surfaces_m.begin(); it != surfaces_m.end(); it++) {
		if ((*it)->getId() == id) {
			std::cout << "Following surface has been deleted:" << std::endl << (*it)->prettyString() << std::endl;
			delete *it;
			surfaces_m.erase(it);
			selected_surfaces_m = surfaces_m; //TODO when deleting a surface currently all remaing surfaces get selected
			return;
		}
	}
	throw std::invalid_argument("[ERROR] ID does not exist: '" + std::to_string(id) + "'.");
}

bool Application::idExists(int id) {
	for (Surface *surface : surfaces_m) {
		if (surface->getId() == id) {
			std::cout << "[WARNING] ID already existing: '" << id << "'. Surface has not been added." << std::endl;
		}
	}
	return false;
}

void Application::read(std::string input) {
	std::string file_path = cli_m.getNextWord(input);

	if (file_path.compare("") == 0) {
		throw std::invalid_argument("[ERROR] No file specified to read from.");
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
			std::cout << "[WARNING] Could not open file at relative path: " << file_path << std::endl;
		}
		file_path = cli_m.getNextWord(input);
	}

	

	cli_m.printAdditionalArguments(input);
}

void Application::store(std::string input) {
	std::string file_path = cli_m.getNextWord(input);
	if (file_path.compare("") == 0) {
		std::cout << "[NOTIFICATION] No file path passed. Content is stored to standard file 'shapes.txt'." << std::endl;
		file_path = "shapes.txt";
	}

	std::vector<Surface*> stored_surfaces;
	std::string mode = cli_m.getNextWord(input);

	if (mode.compare("selected") == 0 || mode.compare("") == 0) {
		stored_surfaces = selected_surfaces_m;
		std::cout << "Storing selected surfaces" << std::endl;
	}
	else if (mode.compare("all") == 0) {
		std::cout << "Storing all loaded surfaces" << std::endl;
		stored_surfaces = surfaces_m;
	}
	else {
		throw std::invalid_argument("[ERROR] Unknown store mode: '" + mode + "'.");
	}

	std::ofstream file(file_path.c_str());
	if (file.is_open()) {
		for (Surface* surface : stored_surfaces) {
			file << *surface << std::endl;
		}
		file.close();
	}
	else {
		throw std::invalid_argument("[ERROR] Could not open file at relative path : '" + file_path + "'.");
	}
	std::cout << "Stored " << stored_surfaces.size() << " surfaces into " << file_path << std::endl;

	cli_m.printAdditionalArguments(input);
}

void Application::selectSurfaces(std::string input) {
	std::string type = cli_m.getNextWord(input);

	if (type.compare("all") == 0 || type.compare("") == 0) {
		selected_surfaces_m = surfaces_m;
		std::cout << "All loaded surfaces have been selected." << std::endl;
		return;
	}
	else if (type.compare("circle") != 0 && type.compare("sector") != 0 && type.compare("polygon") != 0)
	{
		throw std::invalid_argument("[ERROR] Unknown surface type: '" + type + "'.");
	}
	
	std::vector<Surface*>::iterator it = selected_surfaces_m.begin();
	while(it != selected_surfaces_m.end()) {
		std::string temp_name = (*it)->getName();
		cli_m.toLower(temp_name);
		if (type.compare(temp_name) != 0) {
			it = selected_surfaces_m.erase(it);	
		}
		else {
			it++;
		}
	}
	std::cout << "Selected " << selected_surfaces_m.size() << " surfaces" << std::endl;
}

void Application::sortSurfaces(std::string input) {
	std::string type;
	type = cli_m.getNextWord(input);

	if (type.compare("ascending") != 0 && type.compare("descending") != 0) {
		throw std::invalid_argument("[ERROR] Unknown sort mode: '" + type + "'.");
	}

	for (std::vector<Surface*>::iterator it1 = selected_surfaces_m.begin(); it1 != selected_surfaces_m.end(); it1++) {
		for (std::vector<Surface*>::iterator it2 = selected_surfaces_m.begin(); it2 != selected_surfaces_m.end(); it2++) {
			if (*it1 != *it2) {
				if (type.compare("ascending") == 0 && **it1 < **it2) {
					Surface* temp = *it1;
					*it1 = *it2;
					*it2 = temp;
				}
				else if (type.compare("descending") == 0 && **it1 > **it2) {
					Surface* temp = *it1;
					*it1 = *it2;
					*it2 = temp;
				}
			}

		}
	}
	
	//Check if the user added more arguments than neccessary
	cli_m.printAdditionalArguments(input);
}

void Application::printSurfaces(std::string input) {
	std::string mode = cli_m.getNextWord(input);

	if (mode.compare("detailed") == 0) {
		printSurfacesDetailed();
	}
	else if (mode.compare("") == 0) {
		for (Surface *surface : selected_surfaces_m) {
			std::cout << surface->getName() << " " << surface->getId() << std::endl;
		}
	}
	else {
		printSingleSurface(mode);
	}

	
}

void Application::printSingleSurface(std::string input) {
	int id = 0;

	try {
		id = std::stoi(input);
	}
	catch (std::invalid_argument) {
		throw std::invalid_argument("[ERROR] Invalid argument: '" + input + "'. Expected Integer.");
	}
	catch (std::out_of_range) {
		throw std::out_of_range("ERROR] Number too big: '" + input + "'.");
	}

	for (Surface *surface : surfaces_m) {
		if (id == surface->getId()) {
			std::cout << surface->prettyString() << std::endl;
			return;
		}
	}
	throw std::invalid_argument("[ERROR] ID does not exist: '" + std::to_string(id) + "'.");
}

void Application::printSurfacesDetailed() {
	std::cout << "-----------------------------------" << std::endl;
	for (Surface *surface : selected_surfaces_m) {
		std::cout << surface->prettyString() << std::endl;
		std::cout << "-----------------------------------" << std::endl;
	}
}
