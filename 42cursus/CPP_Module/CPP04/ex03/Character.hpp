#pragma once
#ifndef __CHARACTER_HPP__
#define __CHARACTER_HPP__

#include <string>
#include "ICharacter.hpp"

class Character: public ICharacter {

public:
	Character(void);
	Character(std::string const& name);
	Character(Character const& character);
	~Character(void);

	Character&	operator=(Character const& character);

	std::string const&	getName() const;

	void	equip(AMateria* m);
	void	unequip(int idx);
	void	use(int idx, ICharacter& target);

private:
	static int const	S_MAX;

	std::string	name;
	int			s_cnt;
	AMateria*	slot[4];

};

#endif