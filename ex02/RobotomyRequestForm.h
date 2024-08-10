#ifndef ROBOTOMYREQUESTFORM_H_
 #define ROBOTOMYREQUESTFORM_H_

#include "AForm.h"

class RobotomyRequestForm : virtual public AForm
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		~RobotomyRequestForm();

		RobotomyRequestForm(const RobotomyRequestForm& src);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);

		std::string getTarget() const;
		void execute(Bureaucrat const & executor) const;
	private:
		std::string target_;
};


#endif