#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void) {
	{
		// Constructor & Outstream Overloading Test
		std::cout << "------- [ Example 1 ] -------" << std::endl;

		Form	formA;
		Form	formB("paper", 10, 30);

		std::cout << formA << std::endl;
		std::cout << formB << std::endl;
	}

	{
		// Constructor Grade Exception Test
		std::cout << "------- [ Example 2 ] -------" << std::endl;

		try {
			Form	formA("formA", 151, 10);

			std::cout << "formA is 151 grade. wow!" << std::endl;
		}
		catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}

		try {
			Form	formB("formB", 10, 151);

			std::cout << "formB is 151 grade. wow!" << std::endl;
		}
		catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}

		try {
			Form	formC("formC", 0, 10);

			std::cout << "formC is 0 grade. wow!" << std::endl;
		}
		catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}

		try {
			Form	formD("formD", 10, 0);

			std::cout << "formD is 0 grade. wow!" << std::endl;
		}
		catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}

	{
		// Member Function Test
		std::cout << "------- [ Example 3 ] -------" << std::endl;

		Form	formA("formA", 5, 9);
		Bureaucrat	humanA("high man", 5);
		Bureaucrat	humanB("low man", 9);

		std::cout << formA << std::endl;

		humanA.signForm(formA);
		std::cout << formA << std::endl;

		humanB.signForm(formA);
		std::cout << formA << std::endl;
	}

	{
		// OCCF Test
		std::cout << "------- [ Example 4 ] -------" << std::endl;

		Form	formA;
		Form	formB("formB", 1, 2);

		// formA = formB;

		Form	formC(formB);

		std::cout << formB << std::endl;
		std::cout << formC << std::endl;
	}

	return 0;
}
