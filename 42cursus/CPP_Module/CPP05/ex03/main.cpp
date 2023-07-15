#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(void) {
	{
		std::cout << "------- [ Example 1 ] -------" << std::endl;

		Intern	intern;
		AForm*	rrf;

		try {
			rrf = intern.makeForm("robotomy request", "Bender");
			std::cout << *rrf << std::endl;
			delete rrf;
		}
		catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}

	{
		std::cout << "------- [ Example 2 ] -------" << std::endl;

		Intern	intern;
		AForm*	rrf;

		try {
			rrf = intern.makeForm("unknown form", "Bender");
			std::cout << *rrf << std::endl;

			delete rrf;
		}
		catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}

	return 0;
}
