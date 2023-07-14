#include "Bureaucrat.hpp"
#include "Form.hpp"

// Constructor & Destructor
Bureaucrat::Bureaucrat()
:name("default"),
grade(42) {}

Bureaucrat::Bureaucrat(Bureaucrat const& bureaucrat)
:name(bureaucrat.getName()),
grade(bureaucrat.getGrade()) {}

Bureaucrat::Bureaucrat(std::string const& name, int grade)
:name(name),
grade(grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::~Bureaucrat() {}


// Operator overload
std::ostream&	operator<<(std::ostream& os, Bureaucrat const& b) {
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return os;
}


// Exception
char const*	Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high.";
}

char const*	Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low.";
}


// Getter
std::string const&	Bureaucrat::getName(void) const {
	return this->name;
}

int const& Bureaucrat::getGrade(void) const {
	return this->grade;
}


// Member function
void	Bureaucrat::incrementGrade(void) {
	if (this->grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	this->grade -= 1;
}

void	Bureaucrat::decrementGrade(void) {
	if (this->grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade += 1;
}

void	Bureaucrat::signForm(Form& form) {
	try {
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName()
				  << std::endl;
	} catch(std::exception& e) {
		std::cout << this->getName() << " couldn't sign " << form.getName()
				  << "because " << e.what() << std::endl;
	}
}
