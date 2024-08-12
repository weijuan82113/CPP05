#ifndef BUREAUCRAT_H_
 #define BUREAUCRAT_H_

#include <string>
#include <iostream>
#include <exception>

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

		friend std::ostream& operator<<(std::ostream& os,const Bureaucrat& b);

	private:
		const std::string name_;
		int grade_;

};
#endif