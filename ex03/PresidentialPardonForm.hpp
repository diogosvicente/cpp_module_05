#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm {
private:
	std::string _target;

public:
	// Orthodox Canonical Form Class
	PresidentialPardonForm(void);
	PresidentialPardonForm(const PresidentialPardonForm &copy);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &copy);
	virtual ~PresidentialPardonForm();

	// Main Constructor from subject
	PresidentialPardonForm(const std::string &target);

	// Methods required from subject
	virtual void execute(const Bureaucrat &executor) const;
	static AForm *createPresidentialPardonForm(const std::string &target);

	// Operator overload
	friend std::ostream &operator<<(std::ostream &os, const PresidentialPardonForm &aform);
};

#endif
