#pragma once
#ifndef __AMATERIA_HPP__
#define __AMATERIA_HPP__

#include <string>
#include "ICharacter.hpp"

class AMateria {

public:
	AMateria(void);
	AMateria(std::string const& type);
	AMateria(AMateria const& amateria);
	~AMateria(void);

	AMateria& operator=(AMateria const& amateria);

	std::string const&	getType() const;
	virtual AMateria*	clone() const = 0;
	virtual void		use(ICharacter& target);

protected:
	std::string	type;

};

#endif