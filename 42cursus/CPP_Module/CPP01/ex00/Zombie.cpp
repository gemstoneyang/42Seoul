#include <iostream>
#include "Zombie.hpp"

// Constructor & Destructor
Zombie::Zombie(void) {}

Zombie::Zombie(std::string name): name(name) {}

Zombie::~Zombie(void) {
	std::cout << name << ": Grrrrrrrrr..." << std::endl;
}

// Member Function
void 	Zombie::announce(void) {
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
