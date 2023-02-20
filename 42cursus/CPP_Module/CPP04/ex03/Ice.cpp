#include "Ice.hpp"


// Constructor & Destructor
Ice::Ice(void)
:AMateria("ice")
{}

Ice::Ice(std::string const& type)
:AMateria(type)
{}

Ice::Ice(Ice const& ice)
:AMateria(ice.getType())
{}

Ice::~Ice(void) {}


// Operator overload
Ice&	Ice::operator=(Ice const& ice) {
	this->type = ice.getType();
}


// Member function
AMateria*	Ice::clone(void) const {
	AMateria*	ice = new Ice(this->getType());

	return ice;
}

void	Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *"
			  << std::endl;
}
