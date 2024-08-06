#include "Bureaucrat.h"
#include "Form.h"

int main()
{
	try
	{
		Bureaucrat *b = new Bureaucrat("b1", 0);
		Form *f = new Form("f1", 1, 0);
		b->signForm(*f);
		std::cout << *f << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat *b = new Bureaucrat("b2", 150);
		Form *f = new Form("f2", 0, 0);
		b->signForm(*f);
		std::cout << *f << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat *b = new Bureaucrat("b3", 150);
		Form *f = new Form("f3", 1, 0);
		b->signForm(*f);
		std::cout << *f << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat *b = new Bureaucrat("b4", 1);
		Form *f = new Form("f4", 1, 0);
		b->signForm(*f);
		std::cout << *f << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}