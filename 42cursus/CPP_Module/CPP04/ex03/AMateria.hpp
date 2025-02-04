#pragma once
#ifndef __AMATERIA_HPP__
#define __AMATERIA_HPP__

#include <string>

class ICharacter;

class AMateria {

public:
	AMateria(void);
	AMateria(std::string const& type);
	AMateria(AMateria const& amateria);
	virtual ~AMateria(void);

	AMateria&	operator=(AMateria const& amateria);

	std::string const&	getType(void) const;

	virtual AMateria*	clone(void) const = 0;
	virtual void		use(ICharacter& target);

protected:
	std::string	type;

};

#endif