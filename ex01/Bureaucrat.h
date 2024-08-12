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
		Bureaucrat();
		Bureaucrat(const int& grade);
		Bureaucrat(const std::string& name, const int& grade);
		~Bureaucrat();

		Bureaucrat(const Bureaucrat& src);
		Bureaucrat& operator=(const Bureaucrat& other);

		class GradeTooHighException : public std::exception
		{
			public:
				GradeTooHighException();
				~GradeTooHighException() _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW;
				const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW;
			private:
				std::string msg_;
		};

		class GradeTooLowException : public std::exception
		{
			public:
				GradeTooLowException();
				~GradeTooLowException() _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW;
				const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW;
			private:
				std::string msg_;
		};

		std::string getName() const;
		int getGrade() const;
		void GradeIncrement();
		void GradeDecrement();

		std::ostream& operator<<(std::ostream& os) const;
		//ex01
		void signForm(Form& form);

	private:
		const std::string name_;
		int grade_;
		static const int lowest_grade_;
		static const int highest_grade_;

};
#endif