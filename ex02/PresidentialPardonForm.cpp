#include "PresidentialPardonForm.hpp"
#include <iostream>

// Orthodox Canonical Form - 1. Constructor
PresidentialPardonForm::PresidentialPardonForm(void) : AForm("defaultTarget", 25, 5), _target("defaultTarget")
{
    std::cout << RED << "(1) PresidentialPardonForm Default Constructor" << RESET << " called." << std::endl;
}

// Orthodox Canonical Form - 2. Copy constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy)
    : AForm::AForm(copy), _target(copy._target) {}

// Orthodox Canonical Form - 3. Assignment operator overload
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
    AForm::operator=(copy);
    this->_target = copy._target;
    return (*this);
}

// Orthodox Canonical Form - 4. Destructor
PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << RED << "(4) PresidentialPardonForm Destructor" << RESET << " called." << std::endl;
}

// Main Constructor from subject
PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm(target, 25, 5), _target(target)
{
    std::cout << RED << "(5) PresidentialPardonForm Constructor" << RESET << " to Target: " << GREEN << target << RESET << std::endl;
}

// Methods required from subject
void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
    if (!isSigned())
    {
        throw AForm::FormNotSignedException();
    }

    if (executor.getGrade() > getExecuteGrade())
    {
        throw AForm::GradeTooLowException();
    }
    std::cout << GREEN << "Zaphod Beeblebrox has pardoned " << this->_target << "!" << RESET << std::endl;
}

// Operator overload
std::ostream &operator<<(std::ostream &os, const PresidentialPardonForm &aform)
{
    os << "PresidentialPardonForm: " << aform.getName()
       << ", Sign Grade: " << aform.getSignGrade()
       << ", Execute Grade: " << aform.getExecuteGrade()
       << ", Signed: " << (aform.isSigned() ? "Yes" : "No");
    return os;
}
