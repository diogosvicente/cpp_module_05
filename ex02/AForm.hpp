/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioda-si <dioda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 00:34:46 by dioda-si          #+#    #+#             */
/*   Updated: 2023/12/05 00:34:47 by dioda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:
		std::string const _name;
		bool _signed;
		int const _signGrade;
		int const _execGrade;
		static const int _highestGrade = 1;
		static const int _lowestGrade = 150;

	public:
		// Orthodox Canonical AForm
		AForm(void);
		AForm(AForm const &copy);
		AForm const &operator=(AForm const &copy);
		~AForm(void);

		// Others Constructors
		AForm(const std::string &name, int signGrade, int execGrade);
		//AForm(const std::string &name, int signGrade, int execGrade);

		// getters and setters
		const std::string& getName() const;
		bool isSigned() const;
		int getSignGrade() const;
		int getExecuteGrade() const;

		// Methods/Functions
		void beSigned(const Bureaucrat& bureaucrat);
		virtual void execute(const Bureaucrat &executor) const = 0; //criei este método virtual puro (com valor = 0)

		// Exceptions
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

		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class FileOpenException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif
