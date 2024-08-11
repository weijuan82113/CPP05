#include "Intern.h"
#include "AForm.h"
#include "Bureaucrat.h"

__attribute__((destructor))
static void destructor() {
    system("leaks -q Intern");
}

int main()
{
	Intern  someRandomIntern;
    AForm*   rrf;

//Intern creates the presidential pardon
    try
    {
        rrf = someRandomIntern.makeForm("presidential pardon", "Bender1");
        Bureaucrat b("br1_", 5);
        b.signForm(*rrf);
        b.executeForm(*rrf);
        delete(rrf);
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

//Intern creates the robotomy request
    try
    {
        rrf = someRandomIntern.makeForm("robotomy request", "Bender2");
        Bureaucrat b("br2_", 45);
        b.signForm(*rrf);
        b.executeForm(*rrf);
        b.executeForm(*rrf);
        delete(rrf);
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

//Intern creates the shrubbery creation
    try
    {
        rrf = someRandomIntern.makeForm("shrubbery creation", "Bender3");
        Bureaucrat b("br3_", 137);
        b.signForm(*rrf);
        b.executeForm(*rrf);
        delete(rrf);
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

//Intern couldn't creates the form
    try
    {
        rrf = someRandomIntern.makeForm("shrubbery creation_", "Bender4");
        Bureaucrat b("br4_", 137);
        b.signForm(*rrf);
        b.executeForm(*rrf);
        delete(rrf);
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

	return 0;
}
