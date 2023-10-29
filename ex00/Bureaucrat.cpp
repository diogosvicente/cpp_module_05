/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioda-si <dioda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 22:37:03 by dioda-si          #+#    #+#             */
/*   Updated: 2023/10/28 22:37:04 by dioda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 *	Orthodox Canonical Form Class
 *	1. A Bureaucrat constructor that initializes the Bureaucrat.
 *	2. A copy constructor.
 *	3. A copy assignment operator overload.
 *	4. A destructor.
 *
 */

Bureaucrat::Bureaucrat(void)
{
	std::cout << RED << "(1)" << RESET " Bureaucrat constructor called." << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy)
{
	std::cout << RED << "(2)" << RESET << " Copy constructor called." << std::endl;
	*this = copy;
}

Bureaucrat const &Bureaucrat::operator=(Bureaucrat const &copy)
{
	std::cout << RED << "(3)" << RESET << " Assignment operator called." << std::endl;
	this->_name = copy._name;
	this->_grade = copy._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << RED << "(4)" RESET " Destructor called." << std::endl; 
}


Bureaucrat::Bureaucrat(void): _name("default"), _grade(150) {}

Bureaucrat::Bureaucrat(std::string const &name, int grade): _name(name)
{
	this->_grade = grade;
	if (this->_grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	else if (this->_grade > 150)
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

void	Bureaucrat::gradeUp(void)
{
	this->_grade--;
	if (this->_grade < 1)
		throw (Bureaucrat::GradeTooHighException());
}

void	Bureaucrat::gradeDown(void)
{
	this->_grade++;
	if (this->_grade > 150)
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