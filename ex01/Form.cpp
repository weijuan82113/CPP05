#include "Form.h"

Form::Form(std::string name, int grade_sign, int execute_sign)
	:	name_(name),
		is_signed_(false),
		sign_grade_(grade_sign),
		execute_grade_(execute_sign)
{
	if (sign_grade_ > 150)
		throw GradeTooLowException("Form Exception: the grade required has exceeded lowest limit");
	else if (sign_grade_ < 1)
		throw GradeTooHighException("Form Exception: the grade required has exceeded top limit");
}

Form::Form(int grade_sign,int execute_sign)
	:	is_signed_(false),
		sign_grade_(grade_sign),
		execute_grade_(execute_sign)
{
	if (sign_grade_ > 150)
		throw GradeTooLowException("Form Exception: the grade required has exceeded lowest limit");
	else if (sign_grade_ < 1)
		throw GradeTooHighException("Form Exception: the grade required has exceeded top limit");
}

Form::~Form() {}

Form::Form(const Form &src)
	:	name_(src.getName() + "_copy"),
		sign_grade_(src.getSignGrade()),
		execute_grade_(src.getExecuteGrade())
{
	std::cout << "the Form's copy constructor is called, copy" << src.getName() << " into " << name_ << std::endl;
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
Form::GradeTooHighException::~GradeTooHighException() _NOEXCEPT{};

const char* Form::GradeTooHighException::what() const _NOEXCEPT
{
	return msg_.c_str();
}

Form::GradeTooLowException::GradeTooLowException(std::string msg):msg_(msg) {};
Form::GradeTooLowException::~GradeTooLowException() _NOEXCEPT{};

const char* Form::GradeTooLowException::what() const _NOEXCEPT
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

std::ostream& operator<<(std::ostream& os,const Form& f)
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

void Form::beSigned(Bureaucrat &b)
{
	if (b.getGrade() <= sign_grade_)
		is_signed_ = true;
	else
	{
		std::cout << b.getName() << " couldn't sign " << getName() << " because " << '\n';
		throw GradeTooLowException("Bureaucrat's grade is too low to sign");
	}
}