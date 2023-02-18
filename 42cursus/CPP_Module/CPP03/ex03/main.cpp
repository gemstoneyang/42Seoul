#include <iostream>
#include "DiamondTrap.hpp"

int	main(void) {
	DiamondTrap	trap("wonyang");
	DiamondTrap	trap2("tmp");

	std::cout << "\n------- test1 --------\n" << std::endl;

	std::cout << "name:\t" << trap.getName() << std::endl;
	std::cout << "hp:\t" << trap.getHp() << std::endl;
	std::cout << "energy:\t" << trap.getEnergy() << std::endl;
	std::cout << "damage:\t" << trap.getDamage() << std::endl;

	std::cout << "\n------- test2 --------\n" << std::endl;
	
	trap2 = trap;

	std::cout << "name:\t" << trap2.getName() << std::endl;
	std::cout << "hp:\t" << trap2.getHp() << std::endl;
	std::cout << "energy:\t" << trap2.getEnergy() << std::endl;
	std::cout << "damage:\t" << trap2.getDamage() << std::endl;

	std::cout << "\n------- test3 --------\n" << std::endl;

	trap.attack("enemyA");
	std::cout << "\n----------------------\n" << std::endl;
	trap.whoAmI();

	std::cout << "\n----------------------\n" << std::endl;
	trap2.attack("enemyB");
	std::cout << "\n----------------------\n" << std::endl;
	trap2.whoAmI();

	std::cout << "\n----------------------\n" << std::endl;

	return 0;
}
