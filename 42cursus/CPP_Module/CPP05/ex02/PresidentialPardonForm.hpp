#pragma once
#ifndef __PRESIDENTIALPARDONFORM_HPP__
#define __PRESIDENTIALPARDONFORM_HPP__

#include <string.h>
#include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm: public AForm {

public:
	PresidentialPardonForm(void);
	PresidentialPardonForm(PresidentialPardonForm const& pform);
	PresidentialPardonForm(std::string const& target);
	~PresidentialPardonForm(void);

	std::string const&	getTarget(void) const;

	void	execute(Bureaucrat const& executor) const;

private:
	std::string const	target;

	PresidentialPardonForm&	operator=(PresidentialPardonForm const& pform);

};

#endif