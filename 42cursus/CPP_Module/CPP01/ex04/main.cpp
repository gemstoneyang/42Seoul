#include <iostream>
#include <fstream>
#include <string>

void	getBuffer(std::ifstream& instream, std::string& buf) {
	instream.seekg(0, std::ios::end);
	int size = instream.tellg();
	buf.resize(size);
	instream.seekg(0, std::ios::beg);
	instream.read(&buf[0], size);
}

void	changeBuffer(std::string s1, std::string s2, std::string& buf) {
	if (s1 == s2)
		return;

	std::string::size_type	idx;

	while ((idx = buf.find(s1)) != std::string::npos) {
		buf.erase(idx, s1.length());
		buf.insert(idx, s2);
	}
}

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

	std::string	buf;

	getBuffer(instream, buf);
	changeBuffer(argv[2], argv[3], buf);

	std::ofstream	outstream(filename + ".replace");

	outstream << buf;

	return 0;
}
