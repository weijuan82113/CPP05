#include "Form.h"

const int Form::lowest_grade_ = 150;
const int Form::highest_grade_ = 1;

Form::Form()
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

Form::Form(const int& sign_grade,const int& execute_grade)
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

Form::Form(const std::string& name, const int& sign_grade, const int& execute_grade)
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


Form::~Form() {}

Form::Form(const Form &src)
	:	name_(src.getName() + "_copy"),
		sign_grade_(src.getSignGrade()),
		execute_grade_(src.getExecuteGrade())
{
	std::cout << "the Form's copy constructor is called, copy " << src.getName() << " into " << name_ << std::endl;
	*this = src;
}

Form& Form::operator=(const Form& other)
{
	std::cout << "Copy assignment operator is called" << std::endl;
	if (this != &other)
		is_signed_ = other.getIsSigned();
	return *this;
}

Form::GradeTooHighException::GradeTooHighException(std::string msg):msg_(msg) {};
Form::GradeTooHighException::~GradeTooHighException() _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW {};

const char* Form::GradeTooHighException::what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW
{
	return msg_.c_str();
}

Form::GradeTooLowException::GradeTooLowException(std::string msg):msg_(msg) {};
Form::GradeTooLowException::~GradeTooLowException() _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW {};

const char* Form::GradeTooLowException::what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW
{
	return msg_.c_str();
}

std::string Form::getName() const
{
	return name_;
}

bool Form::getIsSigned() const
{
	return is_signed_;
}

int Form::getSignGrade() const
{
	return sign_grade_;
}

int Form::getExecuteGrade() const
{
	return execute_grade_;
}


std::ostream& Form::operator<<(std::ostream& os) const
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

void Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() <= sign_grade_)
		is_signed_ = true;
	else
	{
		std::cout << b.getName() << " couldn't sign " << getName() << " because ";
		throw GradeTooLowException("Bureaucrat's grade is too low to sign");
	}
}