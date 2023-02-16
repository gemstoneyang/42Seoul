#pragma once
#ifndef __CLAPTRAP_HPP__
#define __CLAPTRAP_HPP__

#include <string>

class ClapTrap {

public:
	ClapTrap(void);
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &claptrap);
	~ClapTrap(void);

	ClapTrap& operator=(const ClapTrap &claptrap);

	const std::string&	getName(void);
	const unsigned int&	getHp(void);
	const unsigned int&	getEnergy(void);
	const unsigned int&	getDamage(void);

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

protected:
	std::string		name;
	unsigned int	hp;
	unsigned int	energy;
	unsigned int	damage;

	bool	checkStatus(void);

};

#endif