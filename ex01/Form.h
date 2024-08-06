#ifndef FORM_H_
 #define FORM_H_

#include <string>
#include <iostream>
#include "Bureaucrat.h"

class Bureaucrat;

class Form
{
	public:
		Form(std::string name, int grade_sign, int execute_sign);
		Form(int grade_sign, int execute_sign);
		~Form();

		Form(const Form &src);
		Form& operator=(const Form& other);

		class GradeTooHighException : public std::exception
		{
			public:
				GradeTooHighException(std::string msg);
				~GradeTooHighException() _NOEXCEPT;
				const char* what() const _NOEXCEPT;
			private:
				std::string msg_;
		};

		class GradeTooLowException : public std::exception
		{
			public:
				GradeTooLowException(std::string msg);
				~GradeTooLowException() _NOEXCEPT;
				const char* what() const _NOEXCEPT;
			private:
				std::string msg_;
		};

		std::string getName() const;
		bool getIsSigned() const;
		int getSignGrade() const;
		int getExecuteGrade() const;

		friend std::ostream& operator<<(std::ostream& os,const Form& f);

		void beSigned(Bureaucrat &b);
	private:
		const std::string name_;
		bool is_signed_;
		const int sign_grade_;
		const int execute_grade_;
};

#endif