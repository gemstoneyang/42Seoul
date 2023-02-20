#include <iostream>
#include <stdlib.h>
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

void	leaksCheck(void) {
	system("leaks ex03 | grep leaks");
}

int main(void)
{
	atexit(leaksCheck);

	IMateriaSource* src = new MateriaSource();

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");
	AMateria* tmp;

	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << "\n-----------\n" << std::endl;
	me->unequip(1);
	me->use(1, *bob);
	delete tmp;

	delete bob;
	delete me;
	delete src;

	std::cout << "\n-----------\n" << std::endl;

	return 0;
}