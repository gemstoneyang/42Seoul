#include <iostream>
#include "DiamondTrap.hpp"

// Constructor & Destructor
DiamondTrap::DiamondTrap(void)
:ClapTrap()
{
	std::cout << "DiamondTrap " << ": Default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
:ClapTrap(name + "_clap_name")
{
	std::cout << "DiamondTrap " << name
			  << ": String constructor called" << std::endl;

	this->name = name;
	this->hp = FragTrap::F_HP;
	this->energy = ScavTrap::S_EP;
	this->damage = FragTrap::F_AD;
}

DiamondTrap::DiamondTrap(const DiamondTrap &diamondtrap)
:ClapTrap(diamondtrap.name + "_clap_name")
{
	std::cout << "DiamondTrap: Copy constructor called" << std::endl;

	this->hp = diamondtrap.hp;
	this->energy = diamondtrap.energy;
	this->damage = diamondtrap.damage;
}

DiamondTrap::~DiamondTrap(void) {
	std::cout << "DiamondTrap " << name << ": Destructor called" << std::endl;
}


// Operator Overload
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& diamondtrap) {
	std::cout << "DiamondTrap: Copy assignment operator called" << std::endl;

	ClapTrap::name = diamondtrap.ClapTrap::getName();
	this->name = diamondtrap.name;
	this->hp = diamondtrap.hp;
	this->energy = diamondtrap.energy;
	this->damage = diamondtrap.damage;

	return *this;
}


// Getter
const std::string&	DiamondTrap::getName(void) const {
	return name;
}


// Instance Method
void	DiamondTrap::attack(const std::string& target) {
	std::cout << "DiamondTrap " << name << ": attack() called" << std::endl;

	this->ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void) {
	std::cout << "[ Who am I??? ]" << std::endl;
	std::cout << "DiamondTrap name:\t" << this->name << std::endl;
	std::cout << "ClapTrap name:\t" << this->ClapTrap::name << std::endl;
}
