#include "AForm.hpp"
#include "Bureaucrat.hpp"

// Constructor & Destructor
AForm::AForm(void)
:name("default form"),
isSigned(false),
signGrade(42),
executeGrade(42) {}

AForm::AForm(AForm const& form)
:name(form.getName()),
isSigned(form.getIsSigned()),
signGrade(form.getSignGrade()), 
executeGrade(form.getExecuteGrade()) {}

AForm::AForm(std::string const& name, int const signGrade, int const executeGrade)
:name(name),
isSigned(false),
signGrade(signGrade), 
executeGrade(executeGrade)
{
	if (signGrade < 1 || executeGrade < 1)
		throw AForm::GradeTooHighException();
	else if (signGrade > 150 || executeGrade > 150)
		throw AForm::GradeTooLowException();
}

AForm::~AForm(void) {}


// Operator overload
std::ostream&	operator<<(std::ostream& os, AForm const& f) {
	os << "Name: " << f.getName() 
	   << ", Is Signed: " << std::boolalpha << f.getIsSigned()
	   << ", Required Sign Grade: " << f.getSignGrade()
	   << ", Required Execute Grade: " << f.getExecuteGrade();
	return os;
}


// Exception
char const*	AForm::GradeTooHighException::what() const throw() {
	return "Grade is too high.";
}

char const*	AForm::GradeTooLowException::what() const throw() {
	return "Grade is too low.";
}

char const*	AForm::NoSignExecuteException::what() const throw() {
	return "The sign required for execution is missing.";
}


// Getter
std::string const&	AForm::getName(void) const {
	return this->name;
}

bool const&	AForm::getIsSigned(void) const {
	return this->isSigned;
}

int const&	AForm::getSignGrade(void) const {
	return this->signGrade;
}

int const&	AForm::getExecuteGrade(void) const {
	return this->executeGrade;
}


// Member function
void	AForm::beSigned(Bureaucrat const& b) {
	if (this->signGrade >= b.getGrade()) {
		this->isSigned = true;
		return;
	}
	throw AForm::GradeTooLowException();
}

void	AForm::checkExecutable(Bureaucrat const& b) const {
	if (this->isSigned == false)
		throw AForm::NoSignExecuteException();
	else if (b.getGrade() > this->executeGrade)
		throw AForm::GradeTooLowException();
}
