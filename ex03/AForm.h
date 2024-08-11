#ifndef AFORM_H_
 #define AFORM_H_

#include <string>
#include <iostream>
#include "Bureaucrat.h"

class Bureaucrat;

class AForm
{
	public:
		AForm(std::string name, int sign_grade, int execute_grade);
		AForm(int sign_grade, int execute_grade);
		virtual ~AForm();

		AForm(const AForm& src);
		AForm& operator=(const AForm& other);

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

		//ex02 use the CommonException to show the explicit error message
		class CommonException : public std::exception
		{
			public:
				CommonException(std::string msg);
				~CommonException() _NOEXCEPT;
				const char* what() const _NOEXCEPT;
			private:
				std::string msg_;
		};
		//ex02 ネストされたクラスが継承されないので、ネストクラスを呼ぶ関数をつくる
		void throwCommonException(std::string msg) const;

		std::string getName() const;
		bool getIsSigned() const;
		int getSignGrade() const;
		int getExecuteGrade() const;

		friend std::ostream& operator<<(std::ostream& os,const AForm& f);
		//ex01
		void beSigned(Bureaucrat &b);
		//ex02
		virtual void execute(Bureaucrat const& executor) const = 0;
	private:
		const std::string name_;
		bool is_signed_;
		const int sign_grade_;
		const int execute_grade_;
};

#endif