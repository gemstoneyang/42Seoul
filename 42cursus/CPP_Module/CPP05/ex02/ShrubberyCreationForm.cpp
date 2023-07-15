#include <fstream>
#include <exception>
#include "ShrubberyCreationForm.hpp"

// Constructor & Destructor
ShrubberyCreationForm::ShrubberyCreationForm(void)
:AForm("ShrubberyCreationForm", 145, 137),
target("default target") {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& sform)
:AForm(sform),
target(sform.getTarget()) {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const& target)
:AForm("ShrubberyCreationForm", 145, 137),
target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}


// Getter
std::string const&	ShrubberyCreationForm::getTarget(void) const {
	return this->target;
}


// Member function
void	ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
	checkExecutable(executor);

	std::ofstream	file(this->target + "_shrubbery");

	file << "               ,@@@@@@@,\n"
		<< "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
		<< "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n"
		<< "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n"
		<< "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n"
		<< "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n"
		<< "   `&%\\ ` /%&'    |.|        \\ '|8'\n"
		<< "       |o|        | |         | |\n"
		<< "       |.|        | |         | |\n"
		<< "    \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_" << std::endl;
}