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
#include "Form.hpp"

int main() {
    try {
        Bureaucrat bureaucrat("John", 10);
        Form form("Tax Form", 5, 8);

        std::cout << "Bureaucrat: " << bureaucrat << std::endl;
        std::cout << "Form: " << form << std::endl;

        form.beSigned(bureaucrat);
        std::cout << "After signing the form...\n";
        std::cout << "Form: " << form << std::endl;

        bureaucrat.incrementGrade();
        std::cout << "After incrementing bureaucrat's grade...\n";
        std::cout << "Bureaucrat: " << bureaucrat << std::endl;

        form.signForm(bureaucrat);
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
