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
	Animal::operator=(copy);
	return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << RED << "(4)" RESET " Destructor called." << std::endl; 
}