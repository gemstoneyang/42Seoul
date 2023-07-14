#pragma once
#ifndef __FORM_HPP__
#define __FORM_HPP__

#include <string>
#include <exception>
#include <iostream>

class Bureaucrat;

class Form {

public:
	Form(void);
	Form(std::string const& name, int const signGrade, int const executeGrade);
	~Form(void);


	std::string const&	getName(void) const;
	bool const&			getIsSigned(void) const;
	int const&			getSignGrade(void) const;
	int const&			getExecuteGrade(void) const;

	void	beSigned(Bureaucrat const& b);

private:
	std::string const	name;
	bool				isSigned;
	int const			signGrade;
	int const			executeGrade;

	class GradeTooHighException: public std::exception {
		private:
			char const* what() const throw();
	};

	class GradeTooLowException: public std::exception {
		private:
			char const* what() const throw();
	};

	Form(Form const& form);
	Form&	operator=(Form const& form);
};

std::ostream&	operator<<(std::ostream& os, Form const& f);

#endif