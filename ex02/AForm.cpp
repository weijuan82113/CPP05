#include "AForm.h"

const int AForm::lowest_grade_ = 150;
const int AForm::highest_grade_ = 1;

AForm::AForm()
	:	name_(""), 
		is_signed_(false),
		sign_grade_(1),
		execute_grade_(1)
{
	if (sign_grade_ > lowest_grade_)
		throw GradeTooLowException("Form Exception: the sign grade required has exceeded lowest limit");
	else if (sign_grade_ < highest_grade_)
		throw GradeTooHighException("Form Exception: the sign grade required has exceeded top limit");
	else if (execute_grade_ > lowest_grade_)
		throw GradeTooLowException("Form Exception: the execute grade required has exceeded lowest limit");
	else if (execute_grade_ < highest_grade_)
		throw GradeTooLowException("Form Exception: the execute grade required has exceeded top limit");
}

AForm::AForm(const int& sign_grade,const int& execute_grade)
	:	name_(""),
		is_signed_(false),
		sign_grade_(sign_grade),
		execute_grade_(execute_grade)
{
	if (sign_grade_ > lowest_grade_)
		throw GradeTooLowException("Form Exception: the sign grade required has exceeded lowest limit");
	else if (sign_grade_ < highest_grade_)
		throw GradeTooHighException("Form Exception: the sign grade required has exceeded top limit");
	else if (execute_grade_ > lowest_grade_)
		throw GradeTooLowException("Form Exception: the execute grade required has exceeded lowest limit");
	else if (execute_grade_ < highest_grade_)
		throw GradeTooLowException("Form Exception: the execute grade required has exceeded top limit");
}

AForm::AForm(const std::string& name, const int& sign_grade, const int& execute_grade)
	:	name_(name),
		is_signed_(false),
		sign_grade_(sign_grade),
		execute_grade_(execute_grade)
{
	if (sign_grade_ > lowest_grade_)
		throw GradeTooLowException("Form Exception: the sign grade required has exceeded lowest limit");
	else if (sign_grade_ < highest_grade_)
		throw GradeTooHighException("Form Exception: the sign grade required has exceeded top limit");
	else if (execute_grade_ > lowest_grade_)
		throw GradeTooLowException("Form Exception: the execute grade required has exceeded lowest limit");
	else if (execute_grade_ < highest_grade_)
		throw GradeTooLowException("Form Exception: the execute grade required has exceeded top limit");
}


AForm::~AForm() {}

AForm::AForm(const AForm &src)
	:	name_(src.getName() + "_copy"),
		sign_grade_(src.getSignGrade()),
		execute_grade_(src.getExecuteGrade())
{
	std::cout << "the Form's copy constructor is called, copy " << src.getName() << " into " << name_ << std::endl;
	*this = src;
}

AForm& AForm::operator=(const AForm& other)
{
	std::cout << "Copy assignment operator is called" << std::endl;
	if (this != &other)
		is_signed_ = other.getIsSigned();
	return *this;
}

AForm::GradeTooHighException::GradeTooHighException(std::string msg):msg_(msg) {};
AForm::GradeTooHighException::~GradeTooHighException() _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW {};

const char* AForm::GradeTooHighException::what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW
{
	return msg_.c_str();
}

AForm::GradeTooLowException::GradeTooLowException(std::string msg):msg_(msg) {};
AForm::GradeTooLowException::~GradeTooLowException() _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW {};

const char* AForm::GradeTooLowException::what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW
{
	return msg_.c_str();
}


//------ex02 Common Exception------
AForm::CommonException::CommonException(std::string msg):msg_(msg) {}
AForm::CommonException::~CommonException() _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW {}

const char* AForm::CommonException::what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW
{
	return msg_.c_str();
}

//ネストクラスを呼ぶ関数
void AForm::throwCommonException(const std::string& msg) const
{
	std::cout << "Couldn't execute the form becasue ";
	throw CommonException(msg);
}

//------ex02 Common Exception------

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

std::ostream& AForm::operator<<(std::ostream& os) const
{
	os << "【the form's information】\n"
		<< "name: " + this->getName() << ", is_signed: "
		<< this->getIsSigned()
		<< ", reguired grade: "
		<< this->getSignGrade()
		<< ", executed grade: "
		<< this->getExecuteGrade()
		<< '\n';
	return os;
}

//ex01
void AForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() <= sign_grade_)
		is_signed_ = true;
	else
	{
		std::cout << b.getName() << " couldn't sign " << getName() << " because ";
		throw GradeTooLowException("Bureaucrat's grade is too low to sign");
	}
}