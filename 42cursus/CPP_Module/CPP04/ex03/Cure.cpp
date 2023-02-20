#include "Cure.hpp"


// Constructor & Destructor
Cure::Cure(void)
:AMateria("Cure")
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
}


// Member function
AMateria*	Cure::clone(void) const {
	AMateria*	cure = new Cure(this->getType());

	return cure;
}

void	Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "’s wounds *"
			  << std::endl;
}
