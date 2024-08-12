#ifndef SHRUBBERYCREATIONFORM_H_
 #define SHRUBBERYCREATIONFORM_H_

#include "AForm.h"
#include <fstream>

class ShrubberyCreationForm : virtual public AForm
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		~ShrubberyCreationForm();

		ShrubberyCreationForm(const ShrubberyCreationForm& src);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);

		std::string getTarget() const;
		void execute(const Bureaucrat& executor) const;

	private:
		std::string target_;
};


#endif