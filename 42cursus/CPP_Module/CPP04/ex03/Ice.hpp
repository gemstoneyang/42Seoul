#pragma once
#ifndef __ICE_HPP__
#define __ICE_HPP__

#include "AMateria.hpp"

class Ice: public AMateria {

public:
	Ice(void);
	Ice(std::string const& type);
	Ice(Ice const& ice);
	~Ice(void);

	Ice&	operator=(Ice const& ice);

	AMateria*	clone(void) const;
	void		use(ICharacter& target);

private:

};

#endif