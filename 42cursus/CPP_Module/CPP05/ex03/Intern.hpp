#pragma once
#ifndef __INTERN_HPP__
#define __INTERN_HPP__

#include <string>

class AForm;
class ShrubberyCreationForm;
class RobotomyRequestForm;
class PresidentialPardonForm;

class Intern {

public:
	Intern(void);
	Intern(Intern const& intern);
	~Intern(void);

	Intern&	operator=(Intern const& intern);

	AForm*	makeShrubberyCreationForm(std::string const& target) const;
	AForm*	makeRobotomyRequestForm(std::string const& target) const;
	AForm*	makePresidentialPardonForm(std::string const& target) const;
	AForm*	makeForm(std::string const& formName, std::string const& target) const;

	typedef AForm* (Intern::*funcArr)(std::string const& target) const;

private:
	class InvalidFormNameException: public std::exception {
		private:
			char const* what() const throw();
	};

};

#endif