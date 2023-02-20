#pragma once
#ifndef __CURE_HPP__
#define __CURE_HPP__

#include "AMateria.hpp"

class Cure {

public:
	Cure(void);
	Cure(std::string const& type);
	Cure(Cure const& cure);
	~Cure(void);
	
	Cure&	operator=(Cure const& cure);

	AMateria*	clone(void) const;
	void		use(ICharacter& target);

private:

};

#endif