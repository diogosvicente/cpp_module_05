#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Format.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    Bureaucrat diogo("Diogo", 1);
    ShrubberyCreationForm shrubbery("Test");

    try
    {
        std::cout << shrubbery << std::endl;
        diogo.signForm(shrubbery);
        diogo.executeForm(shrubbery);
        std::cout << shrubbery << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
	return (0);
}
