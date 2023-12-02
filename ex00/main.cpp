/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioda-si <dioda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 18:43:35 by dioda-si          #+#    #+#             */
/*   Updated: 2023/10/29 22:50:51 by dioda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
	// GradeTooHighException
	std::cout << GREEN << "GradeTooHighException Test" << RESET << std::endl;
	try
	{
		Bureaucrat high("High", 0);
		std::cout << high << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "exception message: " << e.what() << std::endl;
	}

	// GradeTooLowException
	std::cout << GREEN << std::endl << "GradeTooLowException Test" << RESET << std::endl;
	try
	{
		Bureaucrat low("Low", 151);
		std::cout << low << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "exception message: " << e.what() << std::endl;
	}

	// incrementGrade
	std::cout << GREEN << std::endl << "incrementingGrande Test" << RESET << std::endl;
	try 
	{
		Bureaucrat inc("Inc", 3);
		std::cout << inc << std::endl;
		inc.incrementGrade();
		std::cout << inc << std::endl;
		inc.incrementGrade();
		std::cout << inc << std::endl;
		inc.incrementGrade();
		std::cout << inc << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "exception message: " << e.what() << std::endl;
	}

	// incrementGrade
	std::cout << GREEN << std::endl << "decrementingGrade Test" << RESET << std::endl;
	try 
	{
		Bureaucrat dec("Dec", 149);
		std::cout << dec << std::endl;
		dec.decrementGrade();
		std::cout << dec << std::endl;
		dec.decrementGrade();
		std::cout << dec << std::endl;
		dec.decrementGrade();
		std::cout << dec << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "exception message: " << e.what() << std::endl;
	}

	std::cout << std::endl << GREEN << "Testing empty constructor" << RESET << std::endl;
	Bureaucrat empty;
	std::cout << ULINE << "Testing gettes in isolation" << RESET << std::endl;
	std::cout << "getName(): " << RED << empty.getName() << RESET << std::endl;
	std::cout << "getGrade(): " << RED << empty.getGrade() << RESET << std::endl;

    return 0;
}
