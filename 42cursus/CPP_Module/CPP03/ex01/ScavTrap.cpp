#include <iostream>
#include "ScavTrap.hpp"

// Constructor & Destructor
ScavTrap::ScavTrap(void)
:ClapTrap()
{
	std::cout << "ScavTrap " << ": Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
:ClapTrap(name)
{
	std::cout << "ScavTrap " << name
			  << ": String constructor called" << std::endl;

	this->hp = 100;
	this->energy = 50;
	this->damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& scavtrap)
:ClapTrap(scavtrap)
{
	std::cout << "ScavTrap: Copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << name << ": Destructor called" << std::endl;
}


// Operator Overload
ScavTrap& ScavTrap::operator=(const ScavTrap &scavtrap) {
	std::cout << "ScavTrap: Copy assignment operator called" << std::endl;

	this->name = scavtrap.name;
	this->hp = scavtrap.hp;
	this->energy = scavtrap.energy;
	this->damage = scavtrap.damage;

	return *this;
}


// Instance Method
void	ScavTrap::attack(const std::string& target) {
	if (!checkStatus())
		return;

	std::cout << "ScavTrap "<< name << " attacks " << target
			  << ", causing " << damage << " points of damage!" << std::endl;
	energy -= 1;
	std::cout << "ScavTrap "<< name << " lefts "
			  << energy << " energy" << std::endl;
}

void	ScavTrap::guardGate(void) {
	std::cout << "ScavTrap: " << name
			  << " is now in Gate keeper mode"<< std::endl;
}
