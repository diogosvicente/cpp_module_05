/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioda-si <dioda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:59:30 by dioda-si          #+#    #+#             */
/*   Updated: 2023/12/02 15:59:37 by dioda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Format.hpp"

int main() {
	customPrint("[Form-Sign] highGrade test", GREEN);
	try
	{
		Form zero("zeroForm", 0, 10);
		std::cout << zero << std::endl;
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	brCustomPrint("[Form-Sign] lowGrade test", GREEN);
	try
	{
		Form first("firstForm", 151, 10);
		std::cout << first << std::endl;
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	brCustomPrint("[Form-Exec] highGrade test", GREEN);
	try
	{
		Form first("firstForm", 10, 0);
		std::cout << first << std::endl;
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	brCustomPrint("[Form-Exec] lowGrade test", GREEN);
	try
	{
		Form first("firstForm", 10, 151);
		std::cout << first << std::endl;
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}	

	brCustomPrint("[Form] right bureucrat test", GREEN);
	try
	{
		Bureaucrat eval("Evaluator", 15);
		Form secondForm("secondForm", 20, 45);
		std::cout << eval << std::endl;
		std::cout << secondForm << std::endl;
		eval.signForm(secondForm);
		std::cout << secondForm << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	
	brCustomPrint("[Form] bureaucrat low grade test", GREEN);
	try
	{
		Bureaucrat cadet("Cadet", 35);
		Form thirdForm("thirdForm", 20, 45);
		std::cout << cadet << std::endl;
		std::cout << thirdForm << std::endl;
		cadet.signForm(thirdForm);
		std::cout << thirdForm << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	brCustomPrint("[Form] within grade limits test - growingBureaucrat", GREEN);
	try
	{
		Bureaucrat growingBureaucrat;
		Form validForm;
		std::cout << growingBureaucrat << std::endl;
		std::cout << validForm << std::endl;
		growingBureaucrat.signForm(validForm);
		std::cout << validForm << std::endl;
		customPrint("-----", YELLOW);
		for (int i = 0; i < 119; i++)
		{
			growingBureaucrat.incrementGrade();
		}
		std::cout << growingBureaucrat << std::endl;
		growingBureaucrat.signForm(validForm);
		std::cout << validForm << std::endl;
		customPrint("-----", YELLOW);
		growingBureaucrat.incrementGrade();
		std::cout << growingBureaucrat << std::endl;
		growingBureaucrat.signForm(validForm);
		std::cout << validForm << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

    return 0;
}
