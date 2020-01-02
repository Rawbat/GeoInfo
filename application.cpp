#include "application.h"
#include <iostream>
#include <string>

Application::Application() {
	quit_m = false;
}

void Application::run() {
	while (!quit_m) {
		std::string input = cli_m.getInput();
		std::string word;
		do {
			word = cli_m.getNextWord(input);
			std::cout << word << std::endl;
		} while (word.compare("") != 0);
		

		/*try {
			command_handler_m.handle(input);
		}
		catch (std::exception &e) {

		}*/
	}
}