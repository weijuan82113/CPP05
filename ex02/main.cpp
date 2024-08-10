#include "AForm.h"
#include "Bureaucrat.h"
#include "PresidentialPardonForm.h"
#include "RobotomyRequestForm.h"
#include "ShrubberyCreationForm.h"

__attribute__((destructor))
static void destructor() {
    system("leaks -q 28B28C");
}

int main()
{

//test PresidentialPardonForm
{
	//construction with targe
	//construction without targe
	//destruction(memory check)
	//copy constructor
	//assignment operator
	//sign without enough grade
	//execute  signed
	//execute without enough grade
	//executed successfully

	//sign without enough grade
	try
	{
		std::cout << "------p1's Common test------\n";
		//construction with targe
		PresidentialPardonForm f1("target1_");
		//construction without targe
		PresidentialPardonForm f2;
		//assignment operator
		f2 = f1;
		std::cout << "------p1's Common test------\n";
		Bureaucrat b1("br1_", 26);
		std::cout << "------p1's sign without enough grade test------\n";
		std::cout << b1 << std::endl;
		std::cout << f2 << std::endl;
		b1.signForm(f2);
		std::cout << "------p1's sign without enough grade test------\n";
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	//execute without signed
	try
	{
		std::cout << "------p2's Common test------\n";
		//construction with targe
		PresidentialPardonForm f1("target1_");
		//copy constructor
		PresidentialPardonForm f2(f1);
		std::cout << "------p2's Common test------\n";
		Bureaucrat b1("br1_", 5);
		std::cout << "------p2's execute without signed test------\n";
		std::cout << b1 << std::endl;
		std::cout << f2 << std::endl;
		b1.executeForm(f2);
		std::cout << "------p2's execute without signed test------\n";
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	//execute without enough grade
	try
	{
		std::cout << "------p3's Common test------\n";
		//construction with targe
		PresidentialPardonForm f1("target1_");
		//copy constructor
		PresidentialPardonForm f2(f1);
		std::cout << "------p3's Common test------\n";
		Bureaucrat b1("br1_", 25);
		std::cout << "------p3's execute without enough grade test------\n";
		b1.signForm(f2);
		std::cout << b1 << std::endl;
		std::cout << f2 << std::endl;
		b1.executeForm(f2);
		std::cout << "------p3's execute without enough grade test------\n";
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	//executed successfully
	try
	{
		std::cout << "------p4's Common test------\n";
		//construction with targe
		PresidentialPardonForm f1("target1_");
		//copy constructor
		PresidentialPardonForm f2(f1);
		std::cout << "------p4's Common test------\n";
		Bureaucrat b1("br1_", 5);
		std::cout << "------p4's successfully test------\n";
		b1.signForm(f2);
		std::cout << b1 << std::endl;
		std::cout << f2 << std::endl;
		b1.executeForm(f2);
		std::cout << "------p4's successfully test------\n";
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

}

//test RobotomyRequestForm
{
	//construction with targe
	//construction without targe
	//destruction(memory check)
	//copy constructor
	//assignment operator
	//sign without enough grade
	//execute without signed
	//execute without enough grade
	//executed successfully

	//sign without enough grade
	try
	{
		std::cout << "------R1's Common test------\n";
		//construction with targe
		RobotomyRequestForm f1("target1_");
		//construction without targe
		RobotomyRequestForm f2;
		//assignment operator
		f2 = f1;
		std::cout << "------R1's Common test------\n";
		Bureaucrat b1("br1_", 73);
		std::cout << "------R1's sign without enough grade test------\n";
		std::cout << b1 << std::endl;
		std::cout << f2 << std::endl;
		b1.signForm(f2);
		std::cout << "------R1's sign without enough grade test------\n";
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	//execute without signed
	try
	{
		std::cout << "------R2's Common test------\n";
		//construction with targe
		RobotomyRequestForm f1("target1_");
		//copy constructor
		RobotomyRequestForm f2(f1);
		std::cout << "------R2's Common test------\n";
		Bureaucrat b1("br1_", 45);
		std::cout << "------R2's execute without signed test------\n";
		std::cout << b1 << std::endl;
		std::cout << f2 << std::endl;
		b1.executeForm(f2);
		std::cout << "------R2's execute without signed test------\n";
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	//execute without enough grade
	try
	{
		std::cout << "------R3's Common test------\n";
		//construction with targe
		RobotomyRequestForm f1("target1_");
		//copy constructor
		RobotomyRequestForm f2(f1);
		std::cout << "------R3's Common test------\n";
		Bureaucrat b1("br1_", 72);
		std::cout << "------R3's execute without enough grade test------\n";
		b1.signForm(f2);
		std::cout << b1 << std::endl;
		std::cout << f2 << std::endl;
		b1.executeForm(f2);
		std::cout << "------R3's execute without enough grade test------\n";
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	//executed successfully
	try
	{
		std::cout << "------R4's Common test------\n";
		//construction with targe
		RobotomyRequestForm f1("target2_");
		//copy constructor
		RobotomyRequestForm f2(f1);
		std::cout << "------R4's Common test------\n";
		Bureaucrat b1("br1_", 45);
		std::cout << "------R4's successfully1 test------\n";
		b1.signForm(f2);
		std::cout << b1 << std::endl;
		std::cout << f2 << std::endl;
		b1.executeForm(f2);
		std::cout << "------R4's successfully1 test------\n";
		std::cout << "------R4's Common test------\n";
		//construction with targe
		RobotomyRequestForm f3("target3_");
		//copy constructor
		RobotomyRequestForm f4(f3);
		std::cout << "------R4's Common test------\n";
		Bureaucrat b2("br2_", 45);
		std::cout << "------R4's successfully2 test------\n";
		b2.signForm(f4);
		std::cout << b2 << std::endl;
		std::cout << f4 << std::endl;
		b1.executeForm(f4);
		std::cout << "------R4's successfully2 test------\n";
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

//test ShrubberyCreationForm
{
	//construction with targe
	//construction without targe
	//destruction(memory check)
	//copy constructor
	//assignment operator
	//sign without enough grade
	//execute without signed
	//execute without enough grade
	//executed successfully

	//sign without enough grade
	try
	{
		std::cout << "------S1's Common test------\n";
		//construction with targe
		ShrubberyCreationForm f1("target3_");
		//construction without targe
		ShrubberyCreationForm f2;
		//assignment operator
		f2 = f1;
		std::cout << "------S1's Common test------\n";
		Bureaucrat b1("br1_", 146);
		std::cout << "------S1's sign without enough grade test------\n";
		std::cout << b1 << std::endl;
		std::cout << f2 << std::endl;
		b1.signForm(f2);
		std::cout << "------S1's sign without enough grade test------\n";
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	//execute without signed
	try
	{
		std::cout << "------S2's Common test------\n";
		//construction with targe
		ShrubberyCreationForm f1("target3_");
		//copy constructor
		ShrubberyCreationForm f2(f1);
		std::cout << "------S2's Common test------\n";
		Bureaucrat b1("br1_", 137);
		std::cout << "------S2's execute without signed test------\n";
		std::cout << b1 << std::endl;
		std::cout << f2 << std::endl;
		b1.executeForm(f2);
		std::cout << "------S2's execute without signed test------\n";
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	//execute without enough grade
	try
	{
		std::cout << "------S3's Common test------\n";
		//construction with targe
		ShrubberyCreationForm f1("target3_");
		//copy constructor
		ShrubberyCreationForm f2(f1);
		std::cout << "------S3's Common test------\n";
		Bureaucrat b1("br1_", 145);
		std::cout << "------S3's execute without enough grade test------\n";
		b1.signForm(f2);
		std::cout << b1 << std::endl;
		std::cout << f2 << std::endl;
		b1.executeForm(f2);
		std::cout << "------S3's execute without enough grade test------\n";
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	//executed successfully
	try
	{
		std::cout << "------S4's Common test------\n";
		//construction with targe
		ShrubberyCreationForm f1("target3_");
		//copy constructor
		ShrubberyCreationForm f2(f1);
		std::cout << "------S4's Common test------\n";
		Bureaucrat b1("br1_", 137);
		std::cout << "------S4's successfully test------\n";
		b1.signForm(f2);
		std::cout << b1 << std::endl;
		std::cout << f2 << std::endl;
		b1.executeForm(f2);
		std::cout << "------S4's successfully test------\n";
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

}
	return 0;
}
