#include "Form.h"

Form::Form(std::string name, int grade_sign):name_(name),is_signed_(false),grade_sign_(grade_sign)
{
	if (grade_sign_ > 150)
		throw GradeTooLowException("Exception: the grade required has exceeded lowest limit");
	else if (grade_sign_ < 1)
		throw GradeTooHighException("Exception: the grade required has exceeded top limit");
}

Form::Form(int grade_sign):is_signed_(false),grade_sign_(grade_sign)
{
	if (grade_sign_ > 150)
		throw GradeTooLowException("Exception: the grade required has exceeded lowest limit");
	else if (grade_sign_ < 1)
		throw GradeTooHighException("Exception: the grade required has exceeded top limit");
}

Form::~Form() {}

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

int Form::getGradeSign() const
{
	return grade_sign_;
}

std::ostream& operator<<(std::ostream& os,const Form& f)
{
	os << "【the form's information】 name: " << f.getName() << ", is_signed: " << f.getIsSigned() << ", reguired grade: " << f.getGradeSign();
	return os;
}

void Form::beSigned(Bureaucrat &b)
{
	if (b.getGrade() <= grade_sign_)
	{
		std::cout << b.getName() << " signed " << name_ << std::endl;
		is_signed_ = true;
	}
	else
		throw GradeTooLowException(b.getName() + " couldn't sign " + name_ + "because the grade is lower than required.");
}