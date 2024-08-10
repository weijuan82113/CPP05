#ifndef BUREAUCRAT_H_
 #define BUREAUCRAT_H_

#include <string>
#include <iostream>
#include <exception>
#include "AForm.h"

class AForm;

class Bureaucrat
{
	public:
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(int grade);
		~Bureaucrat();

		Bureaucrat(const Bureaucrat &src);
		Bureaucrat& operator=(const Bureaucrat& other);

		class GradeTooHighException : public std::exception
		{
			public:
				GradeTooHighException();
				~GradeTooHighException() _NOEXCEPT;
				const char* what() const _NOEXCEPT;
			private:
				std::string msg_;
		};

		class GradeTooLowException : public std::exception
		{
			public:
				GradeTooLowException();
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
		//ex01
		void signForm(AForm& form);
		//ex02
		void executeForm(AForm& form);

	private:
		const std::string name_;
		int grade_;

};
#endif