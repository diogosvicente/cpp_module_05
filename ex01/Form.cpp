/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioda-si <dioda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:58:58 by dioda-si          #+#    #+#             */
/*   Updated: 2023/12/02 15:59:00 by dioda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

const char* Form::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

Form::Form(void)
{
    this->_name = "Blank";
    this->_signed = false;
    this->_signGrade = 30;
    this->_execGrade = 60;
	std::cout << RED << "(1) Form default constructor" << RESET " name: " \
	<< GREEN << this->_name << RESET << ", signGrade: "<< GREEN << this->_signGrade << RESET \
    ", execGrade: " << GREEN << this->_execGrade << RESET << ", signed: " \
    GREEN << this->_signed << RESET << std::endl;
}

Form::Form(const std::string& name, int signGrade, int executeGrade)
    //: _name(name), _signed(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
    this->_name = name;
    this->_signed = false;
    this->_signGrade = signGrade;
    this->_execGrade = executeGrade;
    if (this->_signGrade < this->_highestGrade || this->_execGrade < this->_highestGrade)
        throw Form::GradeTooHighException();
    else if (this->_signGrade > this->_lowestGrade || this->_execGrade > this->_lowestGrade)
        throw Form::GradeTooLowException();
    std::cout << RED << "(5) Form constructor " << RESET << "Name: "\
	<< GREEN << this->_name << RESET << ", signGrade: "<< GREEN << this->_signGrade << RESET \
    ", execGrade: " << GREEN << this->_execGrade << RESET << ", signed: " \
    GREEN << this->_signed << RESET << std::endl;
}

Form::~Form()
{
    std::cout << RED << "(4) Form destructor" RESET " to " << GREEN << this->_name << RESET << " called." << std::endl; 
}

const std::string& Form::getName() const
{
    return _name;
}

bool Form::isSigned() const
{
    return _signed;
}

int Form::getSignGrade() const
{
    return _signGrade;
}

int Form::getExecuteGrade() const
{
    return this->_execGrade;
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() <= this->_signGrade) {
        this->_signed = true;
    } else {
        throw Form::GradeTooLowException();
    }
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
    os << "Form: " << form.getName() << ", Sign Grade: " << form.getSignGrade()
       << ", Execute Grade: " << form.getExecuteGrade() << ", Signed: " << (form.isSigned() ? "Yes" : "No");
    return os;
}
