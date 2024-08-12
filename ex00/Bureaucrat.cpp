#include "Bureaucrat.h"

Bureaucrat::Bureaucrat(const std::string name, int grade):name_(name),grade_(grade)
{
	if (grade > 150)
	{
		throw GradeTooLowException();
	}
	else if (grade < 1)
	{
		throw GradeTooHighException();
	}
}

Bureaucrat::Bureaucrat(int grade):grade_(grade)
{
	if (grade > 150)
	{
		throw GradeTooLowException();
	}
	else if (grade < 1)
	{
		throw GradeTooHighException();
	}
}
Bureaucrat::~Bureaucrat()
{
	std::cout << "the Bureaucrat's descruction: " << this->getName() << " is called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : name_(src.getName() + "copy_")
{
	std::cout << "the Bureaucrat's copy constructor is called, copy " << src.getName() << " into " << name_ << std::endl;
	*this = src;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	std::cout << "Copy assignment operator is called" << std::endl;
	if (this != &other)
		grade_ = other.getGrade();
	return *this;
}

Bureaucrat::GradeTooHighException::GradeTooHighException():msg_("Exception: the grade has exceeded top limit") {};
Bureaucrat::GradeTooHighException::~GradeTooHighException() _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW {};

const char* Bureaucrat::GradeTooHighException::what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW
{
	return msg_.c_str();
}

Bureaucrat::GradeTooLowException::GradeTooLowException():msg_("Exception: the grade has exceeded lowest limit") {};
Bureaucrat::GradeTooLowException::~GradeTooLowException() _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW {};

const char* Bureaucrat::GradeTooLowException::what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW
{
	return msg_.c_str();
}

std::string Bureaucrat::getName() const
{
	return name_;
}

int Bureaucrat::getGrade() const
{
	return grade_;
}

void Bureaucrat::GradeIncrement()
{
	if(--grade_ <= 0)
		throw(GradeTooHighException());
}

void Bureaucrat::GradeDecrement()
{
	if (++grade_ > 150)
		throw(GradeTooHighException());
}

std::ostream& operator<<(std::ostream& os,const Bureaucrat& b)
{
	os <<  b.getName() << ", bureaucrat grade " << b.getGrade();
	return os;
}