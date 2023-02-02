#pragma once
#ifndef __HUMANB_HPP__
#define __HUMANB_HPP__

#include <string>
#include "Weapon.hpp"

class HumanB {

public:
	HumanB(std::string name);

	void	attack(void);
	void	setWeapon(Weapon& weapon);

private:
	std::string	name;
	Weapon		*weapon;

};

#endif