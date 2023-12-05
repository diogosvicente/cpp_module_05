#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Format.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    Bureaucrat diogo("Diogo", 137);
    ShrubberyCreationForm uerj("UERJ");

    try
    {
        std::cout << uerj << std::endl;
        diogo.signForm(uerj);
        diogo.executeForm(uerj);
        std::cout << uerj << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
	return (0);
}
