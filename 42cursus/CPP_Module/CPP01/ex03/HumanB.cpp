#include <iostream>
#include "HumanB.hpp"

HumanB::HumanB(std::string name)
	:name(name), weapon(NULL) {}

void	HumanB::attack(void) {
	if (!weapon) {
		std::cout << name << " doesn't have any weapons" << std::endl;
		return ;
	}
	std::cout << name << " attacks with their " << weapon->getType()
			  << std::endl;
}

void	HumanB::setWeapon(Weapon& weapon) {
	this->weapon = &weapon;
}
