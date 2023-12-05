// Intern.cpp

#include "Intern.hpp"

Intern::Intern(void) {}

Intern::Intern(const Intern &copy) { *this = copy; }

Intern &Intern::operator=(const Intern &copy)
{
    static_cast<void>(copy);
    return (*this);
}

Intern::~Intern() {}

AForm *Intern::makeForm(const std::string &formName, const std::string &target) const
{
    static const char *formNames[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm *(*formCreationFunctions[])(const std::string &) = {
        ShrubberyCreationForm::createShrubberyCreationForm,
        RobotomyRequestForm::createRobotomyRequestForm,
        PresidentialPardonForm::createPresidentialPardonForm};

    for (size_t i = 0; i < sizeof(formNames) / sizeof(formNames[0]); ++i)
    {
        if (formNames[i] == formName)
        {
            std::cout << "Intern creates " << formName << " with target: " << target << std::endl;
            return formCreationFunctions[i](target);
        }
    }

    throw Intern::UnknownFormException();
}

const char *Intern::UnknownFormException::what() const throw()
{
    return "Unknown Form: Intern was unable to create the requested form.";
}