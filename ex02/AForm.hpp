#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:
		std::string _name;
		bool _signed;
		int _signGrade;
		int _execGrade;
		static const int _highestGrade = 1;
    	static const int _lowestGrade = 150;

	public:
		// Orthodox Canonical AForm
		AForm(void);
		AForm(AForm const &copy);
		AForm const &operator=(AForm const &copy);
		~AForm();

		// Others Constructors
		AForm(const std::string& name, int signGrade, int executeGrade);

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
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif
