#include <iostream>
#include "Cure.hpp"
#include "ICharacter.hpp"

// Constructor & Destructor
Cure::Cure(void)
:AMateria("cure")
{}

Cure::Cure(std::string const& type)
:AMateria(type)
{}

Cure::Cure(Cure const& cure)
:AMateria(cure.getType())
{}

Cure::~Cure(void) {}


// Operator overload
Cure&	Cure::operator=(Cure const& cure) {
	this->type = cure.getType();
	return *this;
}


// Member function
AMateria*	Cure::clone(void) const {
	AMateria*	cure = new Cure(this->getType());

	return cure;
}

void	Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *"
			  << std::endl;
}
