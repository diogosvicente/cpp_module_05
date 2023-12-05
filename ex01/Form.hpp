/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioda-si <dioda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:59:03 by dioda-si          #+#    #+#             */
/*   Updated: 2023/12/02 15:59:05 by dioda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		std::string _name;
		bool _signed;
		int _signGrade;
		int _execGrade;
		static const int _highestGrade = 1;
    	static const int _lowestGrade = 150;

	public:
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		// Orthodox Canonical Form
		Form(void);
		Form(Form const &copy);
		Form const &operator=(Form const &copy);
		~Form();

		// Others Constructors
		Form(const std::string& name, int signGrade, int executeGrade);

		// getters and setters
		const std::string& getName() const;
		bool isSigned() const;
		int getSignGrade() const;
		int getExecuteGrade() const;

		// Methods/Functions
		void beSigned(const Bureaucrat& bureaucrat);
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif
