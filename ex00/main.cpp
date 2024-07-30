#include "Bureaucrat.h"

__attribute__((destructor))
static void destructor() {
    system("leaks -q Bureaucrat");
}

int main()
{
	try {
		Bureaucrat br = Bureaucrat(151);
		std::cout << "the name of Bureaucrat is " << br.getName() << std::endl;
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try {
		Bureaucrat br_ = Bureaucrat(1);
		std::cout << "after new constructor1" << std::endl;
		br_.GradeIncrement();
		std::cout << "after Increment" << std::endl;

	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try {
		Bureaucrat br2_ = Bureaucrat("br2_", 1);
		std::cout << "after new constructor2" << std::endl;
		br2_.GradeDecrement();
		std::cout << "after Decrement" << std::endl;
		std::cout << br2_ << std::endl;
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try {
		Bureaucrat br1_ = Bureaucrat("br1_", 1);
		Bureaucrat br2_ = Bureaucrat(br1_);
		std::cout << "after copy" << std::endl;
		std::cout << "the ptr of : " << br1_.getName() << " " << &br1_ << std::endl;
		std::cout << "the ptr of : " << br2_.getName() << " " << &br2_ << std::endl;
		std::cout << "the br2_ : "<< br2_ << std::endl;
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}