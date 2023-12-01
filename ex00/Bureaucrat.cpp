/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioda-si <dioda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 22:37:03 by dioda-si          #+#    #+#             */
/*   Updated: 2023/11/07 15:59:34 by dioda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include "Bureaucrat.hpp"


/**
 *	Orthodox Canonical Form Class
 *	1. A Bureaucrat constructor that initializes the Bureaucrat.
 *	2. A copy constructor.
 *	3. A copy assignment operator overload.
 *	4. A destructor. *
 *	5. A Bureaucrat constructor that initializes the Bureaucrat with a name and grade passed by the user.
 */

Bureaucrat::Bureaucrat(void)//: _name("blank"), _grade(150) {}
{
	this->_name = "Blank";
	this->_grade = 150;
	std::cout << RED << "(1)" << RESET " Default Bureaucrat constructor called with a default name " \
	<< GREEN << this->_name << RESET << " and grade "<< GREEN << this->_grade << RESET << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy)
{
	std::cout << RED << "(2)" << RESET << " Copy constructor called." << std::endl;
	*this = copy;
}

Bureaucrat const &Bureaucrat::operator=(const Bureaucrat &copy)
{
    this->_name = copy._name;
    this->_grade = copy._grade;
    return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << RED << "(4)" RESET " Destructor to " << GREEN << this->_name << RESET << " called." << std::endl; 
}

Bureaucrat::Bureaucrat(std::string const &name, int grade): _name(name)
{
	std::cout << RED << "(5)" RESET " Constructor passing a especific name and grade called." << std::endl; 
	this->_grade = grade;
	if (this->_grade < this->_highestGrade)
		throw (Bureaucrat::GradeTooHighException());
	else if (this->_grade > this->_lowestGrade)
		throw (Bureaucrat::GradeTooLowException());
}


std::string const	&Bureaucrat::getName(void) const
{
	return (this->_name);
}

int const	&Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void	Bureaucrat::incrementGrade(void)
{
	this->_grade--;
	if (this->_grade < this->_highestGrade)
		throw (Bureaucrat::GradeTooHighException());
}

void	Bureaucrat::decrementGrade(void)
{
	this->_grade++;
	if (this->_grade > this->_lowestGrade)
		throw (Bureaucrat::GradeTooLowException());
}

char const	*Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too high");
}

char const	*Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too low");
}

std::ostream	&operator<<(std::ostream &str, Bureaucrat const &bureaucrat)
{
	return (str << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade());
}
