/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioda-si <dioda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:04:31 by dioda-si          #+#    #+#             */
/*   Updated: 2023/12/05 11:04:32 by dioda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

// Orthodox Canonical Form Class - 1.
ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("defaultTarget", 145, 137), _target("defaultTarget")
{
	std::cout << RED << "(1) ShrubberyCreationForm Default Construtor" << RESET << \
	"called. Named: " << GREEN << "defaultTarget" << RESET << std::endl;;
}

// Orthodox Canonical Form Class - 2.
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy)
	: AForm::AForm(copy), _target(copy._target) {}

// Orthodox Canonical Form Class - 3.
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
	AForm::operator=(copy);
	this->_target = copy._target;
	return (*this);
}

// Orthodox Canonical Form Class - 4.
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << RED << "(4) ShrubberyCreationForm Destructor to " << RESET << "called." << std::endl;;
}

// Other Constructors - Main Constructor from subject
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm(target, 145, 137), _target(target)
{
	std::cout << RED << "(5) ShrubberyCreationForm Main Construtor" << RESET << " called, named: " << GREEN << target << RESET << std::endl;;
}

// Methods - required from subject
void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	if (!isSigned())
	{
		throw AForm::FormNotSignedException();
	}

	if (executor.getGrade() > getExecuteGrade())
	{
		throw AForm::GradeTooLowException();
	}

	std::ofstream outFile((this->_target + "_shrubbery").c_str());  // Convertendo explicitamente para const char*
	if (outFile.is_open())
	{
		outFile << SHRUBBERY_TREE;
		outFile.close();
	}
	else
	{
		throw AForm::FileOpenException();
	}
}

// operator overload from subject
std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& aform)
{
	os << "ShrubberyCreationForm: " << aform.getName()
	   << ", Sign Grade: " << aform.getSignGrade()
	   << ", Execute Grade: " << aform.getExecuteGrade()
	   << ", Signed: " << (aform.isSigned() ? "Yes" : "No");
	return os;
}

AForm *ShrubberyCreationForm::createShrubberyCreationForm(const std::string &target)
{
	return new ShrubberyCreationForm(target);
}
