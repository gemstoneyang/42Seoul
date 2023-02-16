#pragma once
#ifndef __FRAGTRAP_HPP__
#define __FRAGTRAP_HPP__

#include "ClapTrap.hpp"

class FragTrap: public ClapTrap {

public:
	FragTrap(std::string name);
	FragTrap(const FragTrap &fragtrap);
	~FragTrap(void);

	FragTrap& operator=(const FragTrap &fragtrap);

	void	highFivesGuys(void);

private:
	FragTrap(void);

};

#endif