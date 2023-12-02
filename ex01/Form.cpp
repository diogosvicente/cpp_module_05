#include "Form.hpp"

//Form::GradeTooHighException::GradeTooHighException() {}
//Form::GradeTooLowException::GradeTooLowException() {}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

Form::Form(void)
{
    this->_name = "Blank";
    this->_signed = false;
    this->_signGrade = 30;
    this->_execGrade = 60;
    std::cout << RED << "(1)" << RESET " Default Form constructor called with a default name " \
	<< GREEN << this->_name << RESET << ", signGrade = "<< GREEN << this->_signGrade << RESET << std::endl;
}

Form::Form(const std::string& name, int signGrade, int executeGrade)
    //: _name(name), _signed(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
    this->_name = name;
    this->_signed = false;
    this->_signGrade = signGrade;
    this->_execGrade = executeGrade;
    if (this->_signGrade < this->_highestGrade || this->_execGrade < 1)
        throw Form::GradeTooHighException();
    else if (this->_signGrade > this->_lowestGrade || this->_execGrade > 150)
        throw Form::GradeTooLowException();
}

Form::~Form() {}

const std::string& Form::getName() const {
    return _name;
}

bool Form::isSigned() const {
    return _signed;
}

int Form::getSignGrade() const {
    return _signGrade;
}

int Form::getExecuteGrade() const {
    return this->_execGrade;
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() <= _signGrade) {
        _signed = true;
    } else {
        throw Form::GradeTooLowException();
    }
}

void Form::signForm(const Bureaucrat& bureaucrat) {
    try {
        beSigned(bureaucrat);
        std::cout << bureaucrat.getName() << " signed " << _name << std::endl;
    } catch (const std::exception& e) {
        std::cout << bureaucrat.getName() << " couldn't sign " << _name << " because " << e.what() << std::endl;
    }
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
    os << "Form: " << form.getName() << ", Sign Grade: " << form.getSignGrade()
       << ", Execute Grade: " << form.getExecuteGrade() << ", Signed: " << (form.isSigned() ? "Yes" : "No");
    return os;
}
