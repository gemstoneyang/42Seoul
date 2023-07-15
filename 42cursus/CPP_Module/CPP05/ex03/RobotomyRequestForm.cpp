#include <cstdlib>
#include <ctime>
#include <iostream>
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void)
:AForm("RobotomyRequestForm", 72, 45),
target("default target") {
	std::srand(std::time(0));
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& rform)
:AForm(rform),
target(rform.getTarget()) {
	std::srand(std::time(0));
}

RobotomyRequestForm::RobotomyRequestForm(std::string const& target)
:AForm("RobotomyRequestForm", 72, 45),
target(target) {
	std::srand(std::time(0));
}

RobotomyRequestForm::~RobotomyRequestForm(void) {}


// Getter
std::string const&	RobotomyRequestForm::getTarget(void) const {
	return this->target;
}


// Member function
void	RobotomyRequestForm::execute(Bureaucrat const& executor) const {
	checkExecutable(executor);

	int randNum = std::rand();

	if (randNum % 2 == 1) {
		std::cout << this->target
				  << " has been robotomized successfully 50% of the time."
				  << std::endl;
	}
	else {
		std::cout << this->target
				  << " has been robotomized failure 50% of the time."
				  << std::endl;
	}
}
