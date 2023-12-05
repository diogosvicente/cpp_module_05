/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioda-si <dioda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:04:25 by dioda-si          #+#    #+#             */
/*   Updated: 2023/12/05 11:04:27 by dioda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>

// Orthodox Canonical Form - 1. Constructor 
RobotomyRequestForm::RobotomyRequestForm(void) : AForm("defaultTarget", 72, 45), _target("defaultTarget")
{
	std::cout << RED << "(1) RobotomyRequestForm Default Constructor" << RESET << " called." << std::endl;
}

// Orthodox Canonical Form - 2. Copy constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy)
	: AForm::AForm(copy), _target(copy._target) {}

// Orthodox Canonical Form - 3. Assignment operator overload
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
	AForm::operator=(copy);
	this->_target = copy._target;
	return (*this);
}

// Orthodox Canonical Form - 4. Destructor
RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << RED << "(4) RobotomyRequestForm Destructor" << RESET << " called." << std::endl;
}

// Main Constructor from subject
RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm(target, 72, 45), _target(target)
{
	std::cout << RED << "(5) RobotomyRequestForm Constructor" << RESET << " to Target: " << GREEN << this->_target << RESET << std::endl;
}

// Methods required from subject
void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	if (!isSigned())
	{
		throw AForm::FormNotSignedException();
	}

	if (executor.getGrade() > getExecuteGrade())
	{
		throw AForm::GradeTooLowException();
	}

	// Simulating the robotomy process with a random success rate of 50%
	std::cout << "* Drilling noises * ";
	if (generateRandomEvenOrOdd() == 0)
	{
		std::cout << GREEN << this->_target << " has been robotomized successfully!" << RESET << std::endl;
	}
	else
	{
		std::cout << RED << "Robotomy failed for " << this->_target << "." << RESET << std::endl;
	}
}

// Operator overload
std::ostream &operator<<(std::ostream &os, const RobotomyRequestForm &aform)
{
	os << "RobotomyRequestForm: " << aform.getName()
	   << ", Sign Grade: " << aform.getSignGrade()
	   << ", Execute Grade: " << aform.getExecuteGrade()
	   << ", Signed: " << (aform.isSigned() ? "Yes" : "No");
	return os;
}

AForm *RobotomyRequestForm::createRobotomyRequestForm(const std::string &target)
{
	return new RobotomyRequestForm(target);
}
