#include <iostream>
#include "FragTrap.hpp"

int	main(void) {
	FragTrap	ct1("wonyang");
	FragTrap	ct2("T1000");

	std::cout << "\n----- Round 1 -----" << std::endl;
	ct1.attack(ct2.getName());
	ct2.takeDamage(ct1.getDamage());

	std::cout << "\n----- Round 2 -----" << std::endl;
	ct2.beRepaired(1000);

	std::cout << "\n----- Round 3 -----" << std::endl;
	for (int i = 0; i < 10; i++)
		ct2.beRepaired(1);
	
	std::cout << "\n----- Round 4 -----" << std::endl;
	ct2.attack(ct1.getName());
	ct2.beRepaired(1);

	std::cout << "\n----- Round 5 -----" << std::endl;
	ct2.takeDamage(500);
	ct2.takeDamage(500);
	ct2.beRepaired(10);

	std::cout << "\n----- Round 6 -----" << std::endl;
	ct1.highFivesGuys();
	ct2.highFivesGuys();

	std::cout << std::endl;

	return 0;
}
