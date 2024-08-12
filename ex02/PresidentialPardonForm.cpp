#include "PresidentialPardonForm.h"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("PresidentialPardonForm", 25, 5),
		target_("") {}


PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: AForm("PresidentialPardonForm", 25, 5),
		target_(target)
{
	std::cout << "<PresidentialPardonForm> Constructor is called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src)
	: AForm(src)
{
	std::cout << "<PresidentialPardonForm> Copy constructor is called" << std::endl;
	*this = src;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	std::cout << "<PresidentialPardonForm> Copy assignment operator is called" << std::endl;
	if (this != &other)
	{
		target_ = other.getTarget();
		AForm::operator=(other);
	}
	return *this;
}

std::string PresidentialPardonForm::getTarget() const
{
	return target_;
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	if (!this->getIsSigned())
		throwCommonException("the form is unsigned\n");
	else if (executor.getGrade() > this->getExecuteGrade())
		throwCommonException("the bureaucrat's execute grade is not enough to execute the form\n");
	else
		std::cout << this->getTarget() + " has been pardoned by Zaphod Beeblebrox\n";
}

