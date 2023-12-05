#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
	private:
		std::string _target;

	public:
		// Orthodox Canonical Form Class
		RobotomyRequestForm(void);
		RobotomyRequestForm(const RobotomyRequestForm &copy);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &copy);
		virtual ~RobotomyRequestForm();

		// Other Constructors - main from subject
		RobotomyRequestForm(const std::string &target);

		// Methods
		virtual void execute(const Bureaucrat &executor) const;
		static AForm *createRobotomyRequestForm(const std::string &target);
};

// Operator Overload
std::ostream &operator<<(std::ostream &os, const RobotomyRequestForm &aform);

#endif
