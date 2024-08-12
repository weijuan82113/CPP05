#ifndef FORM_H_
 #define FORM_H_

#include <string>
#include <iostream>
#include "Bureaucrat.h"

class Bureaucrat;

class Form
{
	public:
		Form();
		Form(const int& sign_grade, const int& execute_grade);
		Form(const std::string& name, const int& sign_grade, const int& execute_grade);
		~Form();

		Form(const Form& src);
		Form& operator=(const Form& other);

		class GradeTooHighException : public std::exception
		{
			public:
				GradeTooHighException(std::string msg);
				~GradeTooHighException() _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW;
				const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW;
			private:
				std::string msg_;
		};

		class GradeTooLowException : public std::exception
		{
			public:
				GradeTooLowException(std::string msg);
				~GradeTooLowException() _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW;
				const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW;
			private:
				std::string msg_;
		};

		std::string getName() const;
		bool getIsSigned() const;
		int getSignGrade() const;
		int getExecuteGrade() const;

		std::ostream& operator<<(std::ostream& os) const;
		//ex01
		void beSigned(const Bureaucrat &b);
	private:
		const std::string name_;
		bool is_signed_;
		const int sign_grade_;
		const int execute_grade_;
		static const int lowest_grade_;
		static const int highest_grade_;
};

#endif