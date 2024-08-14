#include "Bureaucrat.h"
const int Bureaucrat::lowest_grade_ = 150;
const int Bureaucrat::highest_grade_ = 1;

Bureaucrat::Bureaucrat():name_(""), grade_(lowest_grade_) {};

Bureaucrat::Bureaucrat(const int& grade):name_(""), grade_(grade)
{
	if (grade > lowest_grade_)
	{
		throw GradeTooLowException();
	}
	else if (grade < highest_grade_)
	{
		throw GradeTooHighException();
	}
}

Bureaucrat::Bureaucrat(const std::string& name, const int& grade):name_(name),grade_(grade)
{
	if (grade > lowest_grade_)
	{
		throw GradeTooLowException();
	}
	else if (grade < highest_grade_)
	{
		throw GradeTooHighException();
	}
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "the Bureaucrat's destruction: " << this->getName() << " is called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) : name_(src.getName() + "copy_")
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
	if(grade_ == highest_grade_)
		throw(GradeTooHighException());
	--grade_;
}

void Bureaucrat::GradeDecrement()
{
	if (grade_ == lowest_grade_)
		throw(GradeTooLowException());
	++grade_;
}

std::ostream& Bureaucrat::operator<<(std::ostream& os) const
{
	os <<  this->getName() << ", bureaucrat grade " << this->getGrade() << '\n';
	return os;
}

//ex01
void Bureaucrat::signForm(AForm& f)
{
	try
	{
		f.beSigned(*this);
		std::cout << this->getName() + " signed " + f.getName() << '\n';
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
//ex02
void Bureaucrat::executeForm(const AForm& f)
{
	//concrete funcで書くと個々の具象化クラスでエラーを書くべきだ（面倒い）が、ここで書くとthrow catchをどう設計するかを考えるべき
	//具象化クラスでエラーを定義するように設計（common exceptionはAFormの基底クラスに宣言、定義する）※依存関係と柔軟性から考慮したため
	//check the isSigned && grade requirement
	try
	{
		f.execute(*this);
		std::cout << this->getName() + " executed " + f.getName() << '\n';
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}