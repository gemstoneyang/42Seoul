#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void) {
	{
		// Constructor & Outstream Overloading Test
		std::cout << "------- [ Example 1 ] -------" << std::endl;

		Bureaucrat				humanA("wonyang", 42);
		ShrubberyCreationForm	sform("home");

		humanA.executeForm(sform);
		
		humanA.signForm(sform);
		humanA.executeForm(sform);
	}

	{
		std::cout << "------- [ Example 2 ] -------" << std::endl;

		Bureaucrat				humanA("wonyang", 42);
		RobotomyRequestForm		rform("foo");

		humanA.executeForm(rform);

		humanA.signForm(rform);

		for (int i = 0; i < 10; i++) {
			humanA.executeForm(rform);
		}
	}

	{
		std::cout << "------- [ Example 3 ] -------" << std::endl;

		Bureaucrat					humanA("humanA", 42);
		Bureaucrat					humanB("wonyang", 1);
		PresidentialPardonForm		pform("foo");

		humanA.signForm(pform);
		humanB.signForm(pform);

		humanA.executeForm(pform);
		humanB.executeForm(pform);
	}

	return 0;
}
