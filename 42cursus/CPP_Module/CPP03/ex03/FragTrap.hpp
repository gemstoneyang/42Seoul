#pragma once
#ifndef __FRAGTRAP_HPP__
#define __FRAGTRAP_HPP__

#include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap {

public:
	FragTrap(void);
	FragTrap(std::string name);
	FragTrap(const FragTrap &fragtrap);
	~FragTrap(void);

	FragTrap& operator=(const FragTrap &fragtrap);

	void	highFivesGuys(void);

protected:
	const static int	F_HP;
	const static int	F_EP;
	const static int	F_AD;

};

#endif