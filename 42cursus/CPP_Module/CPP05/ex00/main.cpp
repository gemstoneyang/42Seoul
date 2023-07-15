#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

int	main(void) {
	{
		// Constructor & Outstream Overloading Test
		std::cout << "------- [ Example 1 ] -------" << std::endl;

		Bureaucrat	humanA;
		Bureaucrat	humanB("wonyang", 77);

		std::cout << humanA << std::endl;
		std::cout << humanB << std::endl;
	}

	{
		// Constructor Grade Exception Test
		std::cout << "------- [ Example 2 ] -------" << std::endl;

		try {
			Bureaucrat	humanA("wonyang", 151);

			std::cout << "wonyang is 151 grade. wow!" << std::endl;
		}
		catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}

		try {
			Bureaucrat	humanB("wonyang", 0);

			std::cout << "wonyang is 0 grade. wow!" << std::endl;
		}
		catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}

	{
		// Grade Exception Test
		std::cout << "------- [ Example 3 ] -------" << std::endl;

		try {
			Bureaucrat	humanA("wonyang", 7);

			for (int i = 0; i < 10; i++) {
				humanA.incrementGrade();
				std::cout << humanA << std::endl;
			}
		}
		catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}

		try {
			Bureaucrat	humanB("wonyang", 148);

			for (int i = 0; i < 10; i++) {
				humanB.decrementGrade();
				std::cout << humanB << std::endl;
			}
		}
		catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}

	{
		// OCCF Test
		std::cout << "------- [ Example 4 ] -------" << std::endl;

		Bureaucrat	humanA;
		Bureaucrat	humanB("wonyang", 11);

		// humanA = humanB;

		Bureaucrat	humanC(humanB);

		std::cout << humanB << std::endl;
		std::cout << humanC << std::endl;
	}

	return 0;
}
