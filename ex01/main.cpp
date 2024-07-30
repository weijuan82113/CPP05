#include "Bureaucrat.h"
#include "Form.h"


int main()
{
	try
	{
		Bureaucrat *b = new Bureaucrat("b1", 150);
		Form *f = new Form("f1", 0);
		std::cout << *f << std::endl;
		b->signForm(*f);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}