#pragma once
#ifndef __ROBOTOMYREQUESTFORM_HPP__
#define __ROBOTOMYREQUESTFORM_HPP__

#include <string.h>
#include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm: public AForm {

public:
	RobotomyRequestForm(void);
	RobotomyRequestForm(RobotomyRequestForm const& rform);
	RobotomyRequestForm(std::string const& target);
	~RobotomyRequestForm(void);

	std::string const&	getTarget(void) const;

	void	execute(Bureaucrat const& executor) const;

private:
	std::string const	target;

	RobotomyRequestForm&	operator=(RobotomyRequestForm const& rform);

};

#endif