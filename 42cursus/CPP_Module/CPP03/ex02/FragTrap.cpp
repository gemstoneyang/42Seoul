#include <iostream>
#include "FragTrap.hpp"

// Constructor & Destructor
FragTrap::FragTrap(void)
:ClapTrap()
{
	std::cout << "FragTrap " << ": Default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name)
:ClapTrap(name)
{
	std::cout << "FragTrap " << name
			  << ": String constructor called" << std::endl;

	this->hp = 100;
	this->energy = 100;
	this->damage = 30;
}

FragTrap::FragTrap(const FragTrap& fragtrap)
:ClapTrap(fragtrap.name)
{
	std::cout << "FragTrap: Copy constructor called" << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << name << ": Destructor called" << std::endl;
}


// Operator Overload
FragTrap& FragTrap::operator=(const FragTrap &fragtrap) {
	std::cout << "FragTrap: Copy assignment operator called" << std::endl;

	this->name = fragtrap.name;
	this->hp = fragtrap.hp;
	this->energy = fragtrap.energy;
	this->damage = fragtrap.damage;

	return *this;
}

// Instance Method
void	FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << name << ": High five!" << std::endl;
}
