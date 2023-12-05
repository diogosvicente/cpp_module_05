/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioda-si <dioda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 00:34:41 by dioda-si          #+#    #+#             */
/*   Updated: 2023/12/05 00:34:45 by dioda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

// Orthodox Canonical Form - 1
AForm::AForm(void) :  _name("Blank"), _signed(false), _signGrade(30), _execGrade(60)
{
	this->_name = "Blank";
	this->_signed = false;
	this->_signGrade = 30;
	this->_execGrade = 60;
	std::cout << RED << "(1) AForm default constructor" << RESET " name: " \
	<< GREEN << this->_name << RESET << ", signGrade: "<< GREEN << this->_signGrade << RESET \
	", execGrade: " << GREEN << this->_execGrade << RESET << ", signed: " \
	GREEN << this->_signed << RESET << std::endl;
}

// Orthodox Canonical Form - 2
AForm::AForm(AForm const &copy)
{
	std::cout << RED << "(2)" << RESET << " Copy constructor called." << std::endl;
	*this = copy;
}

// Orthodox Canonical Form - 3
AForm const &AForm::operator=(const AForm &copy)
{
	this->_name = copy._name;
	this->_signGrade = copy._signGrade;
	this->_execGrade = copy._execGrade;
	return (*this);
}

// Orthodox Canonical Form - 4
AForm::~AForm(void)
{
	std::cout << RED << "(4) AForm destructor" RESET " to " << GREEN << this->_name << RESET << " called." << std::endl; 
}

// Other Constructors
AForm::AForm(const std::string& name, int signGrade, int executeGrade)
	: _name(name), _signed(false), _signGrade(signGrade), _execGrade(executeGrade)
{
	if (this->_signGrade < this->_highestGrade || this->_execGrade < this->_highestGrade)
		throw AForm::GradeTooHighException();
	else if (this->_signGrade > this->_lowestGrade || this->_execGrade > this->_lowestGrade)
		throw AForm::GradeTooLowException();
	std::cout << RED << "(5) AForm constructor " << RESET << "Name: "\
	<< GREEN << this->_name << RESET << ", signGrade: "<< GREEN << this->_signGrade << RESET \
	", execGrade: " << GREEN << this->_execGrade << RESET << ", signed: " \
	GREEN << this->_signed << RESET << std::endl;
}

// getter and setters
const std::string& AForm::getName() const
{
	return (this->_name);
}

bool AForm::isSigned() const
{
	return (this->_signed);
}

int AForm::getSignGrade() const
{
	return (this->_signGrade);
}

int AForm::getExecuteGrade() const
{
	return (this->_execGrade);
}

// Other Methods
void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= this->_signGrade) {
		this->_signed = true;
	} else {
		throw AForm::GradeTooLowException();
	}
}

// Exceptions
const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return ("Form is not signed");
}

const char *AForm::FileOpenException::what() const throw()
{
	return ("Can't open the file");
}

// Operator Overload
std::ostream& operator<<(std::ostream& os, const AForm& form)
{
	os << "AForm: " << form.getName() << ", Sign Grade: " << form.getSignGrade()
	   << ", Execute Grade: " << form.getExecuteGrade() << ", Signed: " << (form.isSigned() ? "Yes" : "No");
	return os;
}
