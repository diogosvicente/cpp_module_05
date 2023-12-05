#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class AForm;

class Intern
{
	public:
		// Orthodox Canonical Form Class
		Intern(void);
		Intern(const Intern &copy);
		Intern &operator=(const Intern &copy);
		~Intern();

		// Methods required from subject
		AForm *makeForm(const std::string &formName, const std::string &target) const;

		class UnknownFormException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

#endif
