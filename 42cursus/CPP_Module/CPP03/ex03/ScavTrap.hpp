#pragma once
#ifndef __SCAVTRAP_HPP__
#define __SCAVTRAP_HPP__

#include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap {

public:
	ScavTrap(void);
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap& scavtrap);
	~ScavTrap(void);

	ScavTrap& operator=(const ScavTrap &scavtrap);

	void	attack(const std::string& target);
	void	guardGate(void);

protected:
	const static int	S_HP;
	const static int	S_EP;
	const static int	S_AD;

};

#endif