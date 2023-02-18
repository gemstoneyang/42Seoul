#pragma once
#ifndef __DIAMONDTRAP_HPP__
#define __DIAMONDTRAP_HPP__

#include <string>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap: public FragTrap, public ScavTrap {

public:
	DiamondTrap(void);
	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap &diamondtrap);
	~DiamondTrap(void);

	DiamondTrap& operator=(const DiamondTrap& diamondtrap);

	const std::string&	getName(void) const;

	void	attack(const std::string& target);
	void	whoAmI(void);

private:
	std::string	name;


};

#endif