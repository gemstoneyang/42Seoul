#include <iostream>
#include <sstream>
#include <cctype>

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	std::stringstream	ss;
	for (int i = 1; i < argc; i++)
		ss << argv[i];

	std::string	str = ss.str();
	for (size_t i = 0; i < str.size(); i++)
		str[i] = toupper(str[i]);
	std::cout << str << std::endl;
	return 0;
}
