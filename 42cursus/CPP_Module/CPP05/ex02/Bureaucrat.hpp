#pragma once
#ifndef __BUREAUCRAT_HPP__
#define __BUREAUCRAT_HPP__

#include <string>
#include <exception>
#include <iostream>

class AForm;

class Bureaucrat {

public:
	Bureaucrat(void);
	Bureaucrat(Bureaucrat const& bureaucrat);
	Bureaucrat(std::string const& name, int grade);
	~Bureaucrat(void);

	std::string const&	getName(void) const;
	int const&			getGrade(void) const;

	void	incrementGrade(void);
	void	decrementGrade(void);
	void	signForm(AForm& form);
	void	executeForm(AForm const& form) const;

private:
	std::string	const	name;
	int					grade;

	Bureaucrat&	operator=(Bureaucrat const& bureaucrat);

	class GradeTooHighException: public std::exception {
		private:
			char const* what() const throw();
	};

	class GradeTooLowException: public std::exception {
		private:
			char const* what() const throw();
	};

};

std::ostream&	operator<<(std::ostream& os, Bureaucrat const& b);

#endif