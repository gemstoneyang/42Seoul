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

	const std::string&	getName(void) const;
	const unsigned int&	getHp(void) const;
	const unsigned int&	getEnergy(void) const;
	const unsigned int&	getDamage(void) const;

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

protected:
	std::string		name;
	unsigned int	hp;
	unsigned int	energy;
	unsigned int	damage;

	const static int	C_HP;
	const static int	C_EP;
	const static int	C_AD;

	bool	checkStatus(void);

};

#endif