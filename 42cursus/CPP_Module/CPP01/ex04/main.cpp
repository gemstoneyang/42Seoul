#include <iostream>
#include <fstream>
#include <string>

int	main(int argc, char **argv) {
	if (argc != 4) {
		std::cout << "invalid argument" << std::endl;
		return 1;
	}

	std::string		filename = argv[1];
	std::ifstream	instream(filename);

	if (!instream.is_open()) {
		std::cout << "invalid filename" << std::endl;
		return 1;
	}

	std::string	s1 = argv[2];
	std::string	s2 = argv[3];



	return 0;
}
