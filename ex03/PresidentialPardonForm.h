#ifndef PRESIDENTIALPARDONFORM_H_
 #define PRESIDENTIALPARDONFORM_H_

#include "AForm.h"


class PresidentialPardonForm : virtual public AForm
{
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		~PresidentialPardonForm();

		PresidentialPardonForm(const PresidentialPardonForm& src);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& other);

		std::string getTarget() const;
		void execute(const Bureaucrat& executor) const;
	private:
		std::string target_;
};

#endif