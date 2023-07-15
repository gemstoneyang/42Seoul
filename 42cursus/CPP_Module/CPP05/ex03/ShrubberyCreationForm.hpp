#pragma once
#ifndef __SHRUBBERYCREATIONFORM_HPP__
#define __SHRUBBERYCREATIONFORM_HPP__

#include <string.h>
#include "AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm: public AForm {

public:
	ShrubberyCreationForm(void);
	ShrubberyCreationForm(ShrubberyCreationForm const& sform);
	ShrubberyCreationForm(std::string const& target);
	~ShrubberyCreationForm(void);

	std::string const&	getTarget(void) const;

	void	execute(Bureaucrat const& executor) const;

private:
	std::string const	target;

	ShrubberyCreationForm&	operator=(ShrubberyCreationForm const& sform);
};

#endif