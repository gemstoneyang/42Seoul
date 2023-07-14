#include "Form.hpp"
#include "Bureaucrat.hpp"

// Constructor & Destructor
Form::Form(void)
:name("default form"),
isSigned(false),
signGrade(42),
executeGrade(42) {}

// Form::Form(Form const& form) {}

Form::Form(std::string const& name, int const signGrade, int const executeGrade)
:name(name),
isSigned(false),
signGrade(signGrade), 
executeGrade(executeGrade)
{
	if (signGrade < 1 || executeGrade < 1)
		throw Form::GradeTooHighException();
	else if (signGrade > 150 || executeGrade > 150)
		throw Form::GradeTooLowException();
}

Form::~Form(void) {}


// Operator overload
std::ostream&	operator<<(std::ostream& os, Form const& f) {
	os << "Name: " << f.getName() 
	   << ", Is Signed: " << std::boolalpha << f.getIsSigned()
	   << ", Required Sign Grade: " << f.getSignGrade()
	   << ", Required Execute Grade: " << f.getExecuteGrade();
	return os;
}


// Exception
char const*	Form::GradeTooHighException::what() const throw() {
	return "Grade is too high.";
}

char const*	Form::GradeTooLowException::what() const throw() {
	return "Grade is too low.";
}


// Getter
std::string const&	Form::getName(void) const {
	return this->name;
}

bool const&	Form::getIsSigned(void) const {
	return this->isSigned;
}

int const&	Form::getSignGrade(void) const {
	return this->signGrade;
}

int const&	Form::getExecuteGrade(void) const {
	return this->executeGrade;
}


// Member function
void	Form::beSigned(Bureaucrat const& b) {
	if (this->signGrade >= b.getGrade()) {
		this->isSigned = true;
		return;
	}
	throw Form::GradeTooLowException();
}
