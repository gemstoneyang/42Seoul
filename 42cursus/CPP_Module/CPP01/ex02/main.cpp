#include <iostream>
#include <string>

int	main(void) {
	std::string	string = "HI THIS IS BRAIN";
	std::string	*stringPTR = &string;
	std::string	&stringREF = string;

	std::cout << "\t[ Memory Address ]\n"
			  << "&string :\t" << &string << '\n'
			  << "stringPTR :\t" << stringPTR << '\n'
			  << "&stringREF :\t" << &stringREF << std::endl;

	std::cout << "\n\t[ value ]\n"
			  << "string :\t" << string << '\n'
			  << "*stringPTR :\t" << *stringPTR << '\n'
			  << "stringREF :\t" << stringREF << std::endl;

	return 0;
}
