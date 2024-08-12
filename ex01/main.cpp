#include "Bureaucrat.h"
#include "Form.h"
// #include <stdlib.h>

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q Form");
// }

int main()
{
	//test form sign grade limit
	try
	{
		Form *f = new Form("f1", 0, 1);
		*f << std::cout;
		(void) f;
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	//test form execute grade limit
	try
	{
		Form *f = new Form(1, 151);
		*f << std::cout;
		(void) f;
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	//test sign without enough grade
	try
	{
		Bureaucrat *b = new Bureaucrat("b3", 150);
		Form *f = new Form("f3", 1, 1);
		*b << std::cout;
		*f << std::cout;
		b->signForm(*f);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	//sign successfully
	try
	{
		Bureaucrat *b = new Bureaucrat("b4", 150);
		Form *f = new Form("f4", 150, 150);
		*b << std::cout;
		*f << std::cout;
		b->signForm(*f);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	return 0;
}