#include <iostream>
#include "Zombie.hpp"

// Constructor & Destructor
Zombie::Zombie(void) {}

Zombie::~Zombie(void) {
	std::cout << name << ": Grrrrrrrrr..." << std::endl;
}

// Setter
void	Zombie::setName(std::string name) {
	this->name = name;
}

// Member Function
void 	Zombie::announce(void) {
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
