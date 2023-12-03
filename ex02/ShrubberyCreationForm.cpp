#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", 145, 137, target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy)
    : AForm::Form(copy), _target(copy._target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
    AForm::operator=(copy);
	this->_target = copy._target;
	return (*this);
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const{
    if (!isSigned()) {
        throw AForm::FormNotSignedException();
    }

    if (executor.getGrade() > getExecuteGrade()) {
        throw AForm::GradeTooLowException();
    }

    std::ofstream outFile(getName() + "_shrubbery");
    if (outFile.is_open()) {
        outFile << TREE;
        outFile.close();
    } else {
        throw AForm::FileOpenException();
    }
}

