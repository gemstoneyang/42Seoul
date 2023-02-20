#include <iostream>
#include "MateriaSource.hpp"

// Static variable 
int const	MateriaSource::S_MAX = 4;


// Constructor & Destructor
MateriaSource::MateriaSource(void)
:s_cnt(0)
{
	for (int i = 0; i < S_MAX; i++)
		this->slot[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const& ms)
:s_cnt(ms.s_cnt)
{
	for (int i = 0; i < S_MAX; i++)
		this->slot[i] = ms.slot[i];
}

MateriaSource::~MateriaSource(void) {
	for (int i = 0; i < S_MAX; i++) {
		if (this->slot[i])
			delete this->slot[i];
	}
}


// Operator overload
MateriaSource&	MateriaSource::operator=(MateriaSource const& ms) {
	for (int i = 0; i < S_MAX; i++) {
		if (this->slot[i]) {
			delete this->slot[i];
		}
	}

	this->s_cnt = ms.s_cnt;
	for (int i = 0; i < S_MAX; i++)
		this->slot[i] = ms.slot[i];
	return *this;
}


// Member Function
void	MateriaSource::learnMateria(AMateria* m) {
	if (s_cnt >= S_MAX) {
		std::cout << "MateriaSource is FULL!" << std::endl;
		return;
	}

	this->slot[s_cnt] = m;
	s_cnt++;
}

AMateria*	MateriaSource::createMateria(std::string const& type) {
	for (int i = 0; i < s_cnt; i++) {
		if (this->slot[i]->getType() == type)
			return this->slot[i]->clone();
	}
	return NULL;
}
