#include "AForm.h"

AForm::AForm(std::string name, int sign_grade, int execute_grade)
	:	name_(name),
		is_signed_(false),
		sign_grade_(sign_grade),
		execute_grade_(execute_grade)
{
	std::cout << "<AForm> Constructor is called" << std::endl;
	if (sign_grade_ > 150)
		throw GradeTooLowException("Form Exception: the grade required has exceeded lowest limit");
	else if (sign_grade_ < 1)
		throw GradeTooHighException("Form Exception: the grade required has exceeded top limit");
}

AForm::AForm(int sign_grade,int execute_grade)
	:	is_signed_(false),
		sign_grade_(sign_grade),
		execute_grade_(execute_grade)
{
	std::cout << "<AForm> Constructor is called" << std::endl;
	if (sign_grade_ > 150)
		throw GradeTooLowException("Form Exception: the grade required has exceeded lowest limit");
	else if (sign_grade_ < 1)
		throw GradeTooHighException("Form Exception: the grade required has exceeded top limit");
}

AForm::~AForm()
{
	std::cout << "<AForm> Destruction is called" << std::endl;
}

AForm::AForm(const AForm &src)
	:	name_(src.getName() + "_copy"),
		sign_grade_(src.getSignGrade()),
		execute_grade_(src.getExecuteGrade())
{
	std::cout << "<AForm> Copy constructor is called, copy " << src.getName() << " into " << name_ << std::endl;
	*this = src;
}

AForm& AForm::operator=(const AForm& other)
{
	std::cout << "<AForm> Copy assignment operator is called" << std::endl;
	if (this != &other)
		is_signed_ = other.getIsSigned();
	return *this;
}

AForm::GradeTooHighException::GradeTooHighException(std::string msg):msg_(msg) {};
AForm::GradeTooHighException::~GradeTooHighException() _NOEXCEPT{};

const char* AForm::GradeTooHighException::what() const _NOEXCEPT
{
	return msg_.c_str();
}

AForm::GradeTooLowException::GradeTooLowException(std::string msg):msg_(msg) {};
AForm::GradeTooLowException::~GradeTooLowException() _NOEXCEPT{};

const char* AForm::GradeTooLowException::what() const _NOEXCEPT
{
	return msg_.c_str();
}

//------ex02 Common Exception------
AForm::CommonException::CommonException(std::string msg):msg_(msg) {}
AForm::CommonException::~CommonException() _NOEXCEPT {}

const char* AForm::CommonException::what() const _NOEXCEPT
{
	return msg_.c_str();
}

//ネストクラスを呼ぶ関数
void AForm::throwCommonException(std::string msg) const
{
	std::cout << "[Common Exception] ";
	throw CommonException(msg);
}

//------ex02------

std::string AForm::getName() const
{
	return name_;
}

bool AForm::getIsSigned() const
{
	return is_signed_;
}

int AForm::getSignGrade() const
{
	return sign_grade_;
}

int AForm::getExecuteGrade() const
{
	return execute_grade_;
}

std::ostream& operator<<(std::ostream& os,const AForm& f)
{
	os << "【the form's information】\n"
		<< "name: " + f.getName() << ", is_signed: "
		<< f.getIsSigned()
		<< ", reguired grade: "
		<< f.getSignGrade()
		<< ", executed grade: "
		<< f.getExecuteGrade();
	return os;
}

void AForm::beSigned(Bureaucrat &b)
{
	if (b.getGrade() <= sign_grade_)
		is_signed_ = true;
	else
	{
		std::cout << b.getName() << " couldn't sign " << getName() << " because " << '\n';
		throw GradeTooLowException("Bureaucrat's grade is too low to sign");
	}
}