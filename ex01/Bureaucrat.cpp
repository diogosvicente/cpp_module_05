/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioda-si <dioda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:58:41 by dioda-si          #+#    #+#             */
/*   Updated: 2023/12/02 15:58:46 by dioda-si         ###   ########.fr       */
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
 *	5. A Bureaucrat constructor that initializes some Bureaucrat's values.
 */

Bureaucrat::Bureaucrat(void): _name("blank") // (1)
{
	this->_grade = 150;
	std::cout << RED << "(1) Default bureaucrat constructor" << RESET " called with a default name " \
	<< GREEN << this->_name << RESET << " and grade "<< GREEN << this->_grade << RESET << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy) // (2)
{
	std::cout << RED << "(2)" << RESET << " Copy constructor called." << std::endl;
	*this = copy;
}

Bureaucrat const &Bureaucrat::operator=(const Bureaucrat &copy) //(3)
{
	this->_grade = copy._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat(void) // (4)
{
	std::cout << RED << "(4) Bureaucrat destructor" << RESET " to " << GREEN << this->_name << RESET << " called." << std::endl; 
}

Bureaucrat::Bureaucrat(std::string const &name, int grade): _name(name) // (5)
{
	std::cout << RED << "(5) Bureaucrat constructor" RESET "  passing values." << std::endl; 
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

void Bureaucrat::signForm(Form &form)
{
	try {
		form.beSigned(*this);  // Chama o método beSigned da classe Form
		std::cout << this->_name << " signed " << form.getName() << std::endl;
	} catch (const std::exception &e) {
		std::cout << this->_name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
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
