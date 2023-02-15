#include <iostream>
#include "ClapTrap.hpp"

// Constructor & Destructor
ClapTrap::ClapTrap(std::string name)
:name(name),
hp(10),
energy(10),
damage(0)
{
	std::cout << "ClapTrap: " << name << " is Created" << std::endl;
	std::cout << "ClapTrap: String constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &claptrap) {
	std::cout << "ClapTrap: Copy constructor called" << std::endl;

	this->name = claptrap.name;
	this->hp = claptrap.hp;
	this->energy = claptrap.energy;
	this->damage = claptrap.damage;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap: Destructor called" << std::endl;
}

// Operator overload
ClapTrap& operator=(const ClapTrap &claptrap) {
	std::cout << "ClapTrap: Copy assignment operator called" << std::endl;

	this->name = claptrap.name;
	this->hp = claptrap.hp;
	this->energy = claptrap.energy;
	this->damage = claptrap.damage;

	return *this;
}

// Instance Method
void	attack(const std::string& target) {
	
}
