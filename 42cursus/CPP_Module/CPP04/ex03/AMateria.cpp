#include <iostream>
#include "AMateria.hpp"


// Constructor & Destructor
AMateria::AMateria(void) {}

AMateria::AMateria(std::string const& type)
:type(type)
{}

AMateria::AMateria(AMateria const& amateria)
:type(amateria.getType())
{}

AMateria::~AMateria(void)
{}


// Operator overload
AMateria& AMateria::operator=(AMateria const& amateria) {
	this->type = amateria.getType();
}


// Getter
std::string const&	AMateria::getType(void) const {
	return this->type;
}


// Member Function
void	use(ICharacter& target) {
	std::cout << "*do nothing to "<< target.getName() << "*" << std::endl;
}
