#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// Constructor & Destructor
Intern::Intern(void) {}

Intern::Intern(Intern const& intern) {
	*this = intern;
}

Intern::~Intern(void) {}


// Operator overload
Intern&	Intern::operator=(Intern const& intern) {
	(void)intern;
	return *this;
}


// Exception
char const*	Intern::InvalidFormNameException::what() const throw() {
	return "Invalid form name.";
}


// Member function
AForm*	Intern::makeShrubberyCreationForm(std::string const& target) const {
	return new ShrubberyCreationForm(target);
}

AForm*	Intern::makeRobotomyRequestForm(std::string const& target) const {
	return new RobotomyRequestForm(target);
}

AForm*	Intern::makePresidentialPardonForm(std::string const& target) const {
	return new PresidentialPardonForm(target);
}

AForm*	Intern::makeForm(std::string const& formName, std::string const& target) const {
	std::string const	formArr[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	funcArr const		formFuncArr[3] = {&Intern::makeRobotomyRequestForm,
										  &Intern::makePresidentialPardonForm,
										  &Intern::makeShrubberyCreationForm};
	
	int	i = 0;

	while (i < 3) {
		if (formName == formArr[i])
			return (this->*formFuncArr[i])(target);
		i++;
	}
	throw Intern::InvalidFormNameException();
}
