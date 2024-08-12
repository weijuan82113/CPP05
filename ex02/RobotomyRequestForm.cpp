#include "RobotomyRequestForm.h"

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", 72, 45),
		target_("") 
{
	std::srand(static_cast<unsigned int>(std::time(0)));
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm("RobotomyRequestForm", 72, 45),
		target_(target)
{
	std::srand(static_cast<unsigned int>(std::time(0)));
	std::cout << "<RobotomyRequestForm> Constructor is called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src)
	: AForm(src)
{
	std::srand(static_cast<unsigned int>(std::time(0)));
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
		std::cout << "the rand() is " << std::rand() << std::endl;
		if(std::rand() % 2 == 0)
			std::cout << getTarget() + "has been robotomized successfully 50\% of the time\n";
		else
			throwCommonException("The robotomy failed\n");
	}
}