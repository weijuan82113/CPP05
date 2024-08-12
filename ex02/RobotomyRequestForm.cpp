#include "RobotomyRequestForm.h"

unsigned int RobotomyRequestForm::calculate_ratio_ = 0;

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", 72, 45),
		target_("") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm("RobotomyRequestForm", 72, 45),
		target_(target)
{
	std::cout << "<RobotomyRequestForm> Constructor is called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src)
	: AForm(src)
{
	std::cout << "<RobotomyRequestForm> Copy constructor is called" << std::endl;
	*this = src;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
	{
		std::cout << "<RobotomyRequestForm> Copy assignment operator is called" << std::endl;
		target_ = other.getTarget();
		AForm::operator=(other);
	}
	return *this;
}

std::string RobotomyRequestForm::getTarget() const
{
	return target_;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	if (!this->getIsSigned())
		throwCommonException("the form is unsigned\n");
	else if (executor.getGrade() > this->getExecuteGrade())
		throwCommonException("the bureaucrat's execute grade is not enough to execute the form\n");
	else
	{
		calculate_ratio_ ++;
		std::cout << "calculate ratio : " << calculate_ratio_ << std::endl;
		if(calculate_ratio_ % 2 == 0)
			std::cout << getTarget() + "has been robotomized successfully 50\\% \\of the time\n";
		else
			throwCommonException("The robotomy failed\n");
	}
}