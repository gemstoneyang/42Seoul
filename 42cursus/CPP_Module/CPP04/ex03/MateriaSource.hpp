#pragma once
#ifndef __MATERIASOURCE_HPP__
#define __MATERIASOURCE_HPP__

#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource {

public:
	MateriaSource(void);
	MateriaSource(MateriaSource const& ms);
	~MateriaSource(void);

	MateriaSource&	operator=(MateriaSource const& ms);

	void		learnMateria(AMateria* m);
	AMateria*	createMateria(std::string const& type);

private:
	static int const	S_MAX;

	int			s_cnt;
	AMateria*	slot[4];

};

#endif