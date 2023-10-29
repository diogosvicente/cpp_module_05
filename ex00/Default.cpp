/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Default.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioda-si <dioda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 22:37:03 by dioda-si          #+#    #+#             */
/*   Updated: 2023/10/28 22:37:04 by dioda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 *	Orthodox Canonical Form Class
 *	1. A default constructor that initializes the Default-point number value to 0.
 *	2. A copy constructor.
 *	3. A copy assignment operator overload.
 *	4. A destructor.
 *
 */

Default::Default(void):
{
	std::cout << RED << "(1)" << RESET " Default constructor called." << std::endl;
}

Default::Default(Default const &copy)
{
	std::cout << RED << "(2)" << RESET << " Copy constructor called." << std::endl;
	*this = copy;
}

Default const	&Default::operator=(Default const &copy)
{
	std::cout << RED << "(3)" << RESET << " Assignment operator called." << std::endl;
	Animal::operator=(copy);
	return (*this);
}

Default::~Default(void)
{
	std::cout << RED << "(4)" RESET " Destructor called." << std::endl; 
}