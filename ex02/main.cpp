/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioda-si <dioda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 00:35:21 by dioda-si          #+#    #+#             */
/*   Updated: 2023/12/05 00:35:23 by dioda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Utils.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat bureaucrat1("Bureaucrat 1", 1);
	Bureaucrat bureaucrat2("Bureaucrat 2", 75);
	Bureaucrat bureaucrat3("Bureaucrat 3", 150);

	ShrubberyCreationForm shrubbery1("Shrubbery 1");
	ShrubberyCreationForm shrubbery2("Shrubbery 2");
	ShrubberyCreationForm shrubbery3("Shrubbery 3");

	RobotomyRequestForm robotomyForm1("Robotomy 1");
	RobotomyRequestForm robotomyForm2("Robotomy 2");
	RobotomyRequestForm robotomyForm3("Robotomy 3");

	PresidentialPardonForm pardonForm1("Pardon 1");
	PresidentialPardonForm pardonForm2("Pardon 2");
	PresidentialPardonForm pardonForm3("Pardon 3");

	try
	{
		brCustomPrint("[Shrubbery]", YELLOW);
		customPrint("[Shrubbery tests]", ULINE);
		std::cout << bureaucrat1 << std::endl;
		std::cout << shrubbery1 << std::endl;
		bureaucrat1.signForm(shrubbery1);
		bureaucrat1.executeForm(shrubbery1);
		std::cout << shrubbery1 << std::endl;

		brCustomPrint("[Shrubbery tests]", ULINE);
		std::cout << bureaucrat2 << std::endl;
		std::cout << shrubbery2 << std::endl;
		bureaucrat2.signForm(shrubbery2);
		bureaucrat2.executeForm(shrubbery2);
		std::cout << shrubbery2 << std::endl;

		brCustomPrint("[Shrubbery tests]", ULINE);
		std::cout << bureaucrat3 << std::endl;
		std::cout << shrubbery3 << std::endl;
		bureaucrat3.signForm(shrubbery3);
		bureaucrat3.executeForm(shrubbery3);
		std::cout << shrubbery3 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		brCustomPrint("[Robotomy]", YELLOW);
		customPrint("[Robotomy tests]", ULINE);
		std::cout << bureaucrat1 << std::endl;
		std::cout << robotomyForm1 << std::endl;
		bureaucrat1.signForm(robotomyForm1);
		bureaucrat1.executeForm(robotomyForm1);
		std::cout << robotomyForm1 << std::endl;

		brCustomPrint("[Robotomy tests]", ULINE);
		std::cout << bureaucrat2 << std::endl;
		std::cout << robotomyForm2 << std::endl;
		bureaucrat2.signForm(robotomyForm2);
		bureaucrat2.executeForm(robotomyForm2);
		std::cout << robotomyForm2 << std::endl;

		brCustomPrint("[Robotomy tests]", ULINE);
		std::cout << bureaucrat3 << std::endl;
		std::cout << robotomyForm3 << std::endl;
		bureaucrat3.signForm(robotomyForm3);
		bureaucrat3.executeForm(robotomyForm3);
		std::cout << robotomyForm3 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		brCustomPrint("[Presidential]", YELLOW);
		customPrint("[Presidential Pardon tests]", ULINE);
		std::cout << bureaucrat1 << std::endl;
		std::cout << pardonForm1 << std::endl;
		bureaucrat1.signForm(pardonForm1);
		bureaucrat1.executeForm(pardonForm1);
		std::cout << pardonForm1 << std::endl;

		brCustomPrint("[Presidential Pardon tests]", ULINE);
		std::cout << bureaucrat2 << std::endl;
		std::cout << pardonForm2 << std::endl;
		bureaucrat2.signForm(pardonForm2);
		bureaucrat2.executeForm(pardonForm2);
		std::cout << pardonForm2 << std::endl;

		brCustomPrint("[Presidential Pardon tests]", ULINE);
		std::cout << bureaucrat3 << std::endl;
		std::cout << pardonForm3 << std::endl;
		bureaucrat3.signForm(pardonForm3);
		bureaucrat3.executeForm(pardonForm3);
		std::cout << pardonForm3 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
