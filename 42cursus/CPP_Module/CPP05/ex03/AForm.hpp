#pragma once
#ifndef __AFORM_HPP__
#define __AFORM_HPP__

#include <string>
#include <exception>
#include <iostream>

class Bureaucrat;

class AForm {

public:
	AForm(void);
	AForm(AForm const& form);
	AForm(std::string const& name, int const signGrade, int const executeGrade);
	virtual ~AForm(void);

	std::string const&	getName(void) const;
	bool const&			getIsSigned(void) const;
	int const&			getSignGrade(void) const;
	int const&			getExecuteGrade(void) const;

	void			beSigned(Bureaucrat const& b);
	void			checkExecutable(Bureaucrat const& b) const;
	virtual void	execute(Bureaucrat const& executor) const = 0;

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

	class NoSignExecuteException: public std::exception {
		private:
			char const* what() const throw();
	};

	AForm&	operator=(AForm const& form);
};

std::ostream&	operator<<(std::ostream& os, AForm const& f);

#endif