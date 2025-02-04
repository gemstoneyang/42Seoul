#include <iostream>
#include "ClapTrap.hpp"

// Constructor & Destructor

ClapTrap::ClapTrap(void) {}

ClapTrap::ClapTrap(std::string name)
:name(name),
hp(10),
energy(10),
damage(0)
{
	std::cout << "ClapTrap " << name
			  << ": String constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &claptrap) {
	std::cout << "ClapTrap: Copy constructor called" << std::endl;

	this->name = claptrap.name;
	this->hp = claptrap.hp;
	this->energy = claptrap.energy;
	this->damage = claptrap.damage;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << name
			  << ": Destructor called" << std::endl;
}


// Operator Overload
ClapTrap& ClapTrap::operator=(const ClapTrap &claptrap) {
	std::cout << "ClapTrap: Copy assignment operator called" << std::endl;

	this->name = claptrap.name;
	this->hp = claptrap.hp;
	this->energy = claptrap.energy;
	this->damage = claptrap.damage;

	return *this;
}


// Getter
const std::string&	ClapTrap::getName(void) {
	return name;
}

const unsigned int&	ClapTrap::getHp(void) {
	return hp;
}

const unsigned int&	ClapTrap::getEnergy(void) {
	return energy;
}

const unsigned int&	ClapTrap::getDamage(void) {
	return damage;
}


// Private Function
bool	ClapTrap::checkStatus(void) {
	if (hp == 0) {
		std::cout << "ClapTrap " << name
				  << ": No Hit point left" << std::endl;
		return false;
	}
	else if (energy < 1) {
		std::cout << "ClapTrap " << name
				  << ": Not enough energy" << std::endl;
		return false;
	}
	return true;
}

// Instance Method
void	ClapTrap::attack(const std::string& target) {
	if (!checkStatus())
		return;

	std::cout << "ClapTrap "<< name << " attacks " << target
			  << ", causing " << damage << " points of damage!" << std::endl;
	energy -= 1;
	std::cout << "ClapTrap "<< name << " lefts "
			  << energy << " energy" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	std::cout << "ClapTrap "<< name << " takes "
			  << amount << " points of damage!" << std::endl;
	
	if (hp < amount)
		hp = 0;
	else
		hp -= amount;
	std::cout << "ClapTrap "<< name << " lefts "
			  << hp << " hp" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (!checkStatus())
		return;

	std::cout << "ClapTrap "<< name << " has repaired "
			  << amount << " points of hp!" << std::endl;
	
	if (hp + amount < 1000)
		hp += amount;
	else
		hp = 999;
	energy -= 1;
	std::cout << "ClapTrap "<< name << " lefts "
			  << hp << " hp" << std::endl;
	std::cout << "ClapTrap "<< name << " lefts "
			  << energy << " energy" << std::endl;
}
