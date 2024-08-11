#include "Intern.h"

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern& src)
{
	std::cout << "<Intern>  Copy constructor is called" << std::endl;
	*this = src;
}

Intern& Intern::operator=(const Intern& other)
{
	std::cout << "<Intern> Copy assignment operator is called" << std::endl;
	if (this != &other)
		(void)other;
	return *this;
}

AForm* Intern::makeForm(std::string name, std::string target)
{
	std::string names[] = {
		"presidential pardon",
		"robotomy request",
		"shrubbery creation"
	};

	AForm* forms[] = {
		new PresidentialPardonForm(target),
		new RobotomyRequestForm(target),
		new ShrubberyCreationForm(target)
	};

	AForm* ret_form = NULL;
	for(int i(0); i < 3; i++)
	{
		if (name == names[i])
			ret_form = forms[i];
		else
			delete forms[i];
	}

	if (!ret_form)
		ret_form->throwCommonException("Couldn't create " + name);
	else
		std::cout << "Intern creates " << name << std::endl;
	return ret_form;
}