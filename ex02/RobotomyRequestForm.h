#ifndef ROBOTOMYREQUESTFORM_H_
 #define ROBOTOMYREQUESTFORM_H_

#include "AForm.h"
#include <ctime>
#include <cstdlib>

class RobotomyRequestForm : virtual public AForm
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		~RobotomyRequestForm();

		RobotomyRequestForm(const RobotomyRequestForm& src);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);

		std::string getTarget() const;
		void execute(const Bureaucrat& executor) const;
	private:
		std::string target_;
		static unsigned int calculate_ratio_;
};


#endif