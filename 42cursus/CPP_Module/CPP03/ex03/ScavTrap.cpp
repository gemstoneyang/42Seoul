#include <iostream>
#include "ScavTrap.hpp"

// Static Variable Initialize
const int	ScavTrap::S_HP = 100;
const int	ScavTrap::S_EP = 50;
const int	ScavTrap::S_AD = 20;


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

	this->hp = S_HP;
	this->energy = S_EP;
	this->damage = S_AD;
}

ScavTrap::ScavTrap(const ScavTrap& scavtrap)
:ClapTrap(scavtrap.name)
{
	std::cout << "ScavTrap: Copy constructor called" << std::endl;

	this->hp = scavtrap.hp;
	this->energy = scavtrap.energy;
	this->damage = scavtrap.damage;
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
