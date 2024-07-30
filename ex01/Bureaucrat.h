#ifndef BUREAUCRAT_H_
 #define BUREAUCRAT_H_

#include <string>
#include <iostream>
#include <exception>
#include "Form.h"

class Form;

class Bureaucrat
{
	public:
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(int grade);
		~Bureaucrat();

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
		int getGrade() const;
		void GradeIncrement();
		void GradeDecrement();

		friend std::ostream& operator<<(std::ostream& os,const Bureaucrat& b);

		void signForm(Form &f);
	private:
		const std::string name_;
		int grade_;

};
#endif