#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Utils.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	Intern someRandomIntern;
    AForm *rrf;

    try
    {
		customPrint("Shrubbery Test", YELLOW);
		rrf = someRandomIntern.makeForm("shrubbery creation", "UERJ");
        std::cout << *rrf << std::endl;
        //delete rrf;


		brCustomPrint("Robotomy Test", YELLOW);
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        std::cout << *rrf << std::endl;
        //delete rrf; // Don't forget to delete the created form to avoid memory leaks

       	brCustomPrint("Presidential Test", YELLOW);
        rrf = someRandomIntern.makeForm("presidential pardon", "Sinner");
        std::cout << *rrf << std::endl;
        //delete rrf;

		brCustomPrint("Unknown Test", YELLOW);
        // Trying to create an unknown form
        rrf = someRandomIntern.makeForm("unknown form", "Unknown");
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

	return (0);
}
