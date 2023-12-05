/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioda-si <dioda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:04:44 by dioda-si          #+#    #+#             */
/*   Updated: 2023/12/05 11:04:47 by dioda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Utils.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	Intern someRandomIntern;
    Bureaucrat	normal("Normal", 25);
    AForm *rrf;

    try
    {
		customPrint("Shrubbery Test", YELLOW);
		rrf = someRandomIntern.makeForm("shrubbery creation", "UERJ");
        std::cout << *rrf << std::endl;
        delete rrf; //to avoid memory leaks

		brCustomPrint("Robotomy Test", YELLOW);
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        std::cout << *rrf << std::endl;
        delete rrf;

       	brCustomPrint("Presidential Test", YELLOW);
        rrf = someRandomIntern.makeForm("presidential pardon", "Sinner");
        std::cout << *rrf << std::endl;
        delete rrf;

		brCustomPrint("Unknown Test", YELLOW);
        // Trying to create an unknown form
        rrf = someRandomIntern.makeForm("unknown form", "Unknown");
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

	brCustomPrint("Sign and Execute Tests", YELLOW);
	rrf = someRandomIntern.makeForm("shrubbery creation", "42 Rio");
	rrf->beSigned(normal);
	normal.executeForm(*rrf);
	delete rrf;
    
    brCustomPrint("Sign and Execute Tests", YELLOW);
	rrf = someRandomIntern.makeForm("presidential pardon", "Lex Luthor");
	normal.signForm(*rrf);
	normal.executeForm(*rrf);
	delete rrf;

	return (0);
}
