#ifndef AFORM_H_
 #define AFORM_H_

#include <string>
#include <iostream>
#include "Bureaucrat.h"

class Bureaucrat;

class AForm
{
	public:
		AForm();
		AForm(const int& sign_grade, const int& execute_grade);
		AForm(const std::string& name, const int& sign_grade, const int& execute_grade);
		virtual ~AForm();

		AForm(const AForm& src);
		AForm& operator=(const AForm& other);

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

		//ex02 use the CommonException to show the explicit error message
		class CommonException : public std::exception
		{
			public:
				CommonException(std::string msg);
				~CommonException() _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW;
				const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW;
			private:
				std::string msg_;
		};
		//ex02 ネストされたクラスが継承されないので、ネストクラスを呼ぶ関数をつくる
		void throwCommonException(const std::string& msg) const;

		std::string getName() const;
		bool getIsSigned() const;
		int getSignGrade() const;
		int getExecuteGrade() const;

		std::ostream& operator<<(std::ostream& os) const;
		//ex01
		void beSigned(const Bureaucrat &b);
		//ex02
		virtual void execute(const Bureaucrat& executor) const = 0;
	private:
		const std::string name_;
		bool is_signed_;
		const int sign_grade_;
		const int execute_grade_;
		static const int lowest_grade_;
		static const int highest_grade_;
};

#endif