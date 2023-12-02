#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

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

		Form(void);
		Form(const std::string& name, int signGrade, int executeGrade);
		~Form();

		const std::string& getName() const;
		bool isSigned() const;
		int getSignGrade() const;
		int getExecuteGrade() const;

		void beSigned(const Bureaucrat& bureaucrat);
		void signForm(const Bureaucrat& bureaucrat);
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif
