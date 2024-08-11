#ifndef INTERN_H_
 #define INTERN_H_

#include "AForm.h"
#include "PresidentialPardonForm.h"
#include "RobotomyRequestForm.h"
#include "ShrubberyCreationForm.h"

class Intern
{
	public:
		Intern();
		~Intern();

		Intern(const Intern& src);
		Intern& operator=(const Intern& other);

		AForm* makeForm(std::string name, std::string target);
};

#endif