#include <iostream>
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void)
:AForm("PresidentialPardonForm", 25, 5),
target("default target") {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& pform)
:AForm(pform),
target(pform.getTarget()) {}

PresidentialPardonForm::PresidentialPardonForm(std::string const& target)
:AForm("PresidentialPardonForm", 25, 5),
target(target) {}

PresidentialPardonForm::~PresidentialPardonForm(void) {}


// Getter
std::string const&	PresidentialPardonForm::getTarget(void) const {
	return this->target;
}


// Member function
void	PresidentialPardonForm::execute(Bureaucrat const& executor) const {
	checkExecutable(executor);

	std::cout << this->target
			  << " has been pardoned by Zafod Beeblebrox."
			  << std::endl;
}