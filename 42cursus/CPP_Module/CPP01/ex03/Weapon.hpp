#pragma once
#ifndef __WEAPON_HPP__
#define __WEAPON_HPP__

#include <string>

class Weapon {

public:
	Weapon(std::string type);

	std::string&	getType(void);
	void			setType(std::string	type);

private:
	std::string	type;

};

#endif