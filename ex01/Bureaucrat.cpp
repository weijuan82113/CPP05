#include "Bureaucrat.h"

Bureaucrat::Bureaucrat(const std::string name, int grade):name_(name),grade_(grade)
{
	if (grade > 150)
	{
		throw GradeTooLowException("Exception: the grade has exceeded lowest limit");
	}
	else if (grade < 1)
	{
		throw GradeTooHighException("Exception: the grade has exceeded top limit");
	}
}

Bureaucrat::Bureaucrat(int grade):grade_(grade)
{
	if (grade > 150)
	{
		throw GradeTooLowException("Exception: the grade has exceeded lowest limit");
	}
	else if (grade < 1)
	{
		throw GradeTooHighException("Exception: the grade has exceeded top limit");
	}
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::GradeTooHighException::GradeTooHighException(std::string msg):msg_(msg) {};
Bureaucrat::GradeTooHighException::~GradeTooHighException() _NOEXCEPT{};

const char* Bureaucrat::GradeTooHighException::what() const _NOEXCEPT
{
	return msg_.c_str();
}

Bureaucrat::GradeTooLowException::GradeTooLowException(std::string msg):msg_(msg) {};
Bureaucrat::GradeTooLowException::~GradeTooLowException() _NOEXCEPT{};

const char* Bureaucrat::GradeTooLowException::what() const _NOEXCEPT
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
		throw(GradeTooHighException("Exception: the grade has exceeded top limit"));
}

void Bureaucrat::GradeDecrement()
{
	if (++grade_ > 150)
		throw(GradeTooHighException("Exception: the grade has exceeded lowest limit"));
}

std::ostream& operator<<(std::ostream& os,const Bureaucrat& b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return os;
}

void Bureaucrat::signForm(Form &f)
{
	if (f.getName() == "")
	{
		std::cout << "The form name is not filled" << std::endl;
		return;
	}
	else if (this->getName() == "")
	{
		std::cout << "The Bureaucrat name is not filled" << std::endl;
		return;
	}
	f.beSigned(*this);
}