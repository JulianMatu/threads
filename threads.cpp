// threads.cpp
#include "threads.hpp"

/*
* index 0 of argv is the name of the program
* indices 1 - max is the rest of the arguments
* argc is the number of arguments
*/

int main(int argc, char* argv[])
{	
	// if no input arguments, terminate
	if (argc < 2) {
		printf("No input given, terminating...\n");
		return 1;
	}

	// construct array with integer arguments
	std::vector<int> arguments;
	for (size_t i = 1; i < argc; i++) {
		// handle input errors by printing error to user and terminating program
		try {
			arguments.push_back(std::stoi(argv[i]));
		}
		catch (...) {
			printf("Invalid executable arguments, terminating...\n");
			return 1;
		}
	}

	// print arguments
	printf("The following integers have been parsed: ");
	for (auto n : arguments) {
		printf("%d ", n);
	}
	printf("\n");

	// start tests
	if (startTests(arguments)) {
		printf("All tests have passed.\n");
	}
	else {
		printf("One or more tests have failed.\n");
	}

	return 0;
}