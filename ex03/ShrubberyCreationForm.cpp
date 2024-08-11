#include "ShrubberyCreationForm.h"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137) {}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "<ShrubberyCreationForm> Destruction is called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("ShrubberyCreationForm", 145, 137),
		target_(target)
{
	std::cout << "<ShrubberyCreationForm> Constructor is called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src)
	: AForm(src)
{
	std::cout << "<ShrubberyCreationForm> Copy constructor is called" << std::endl;
	*this = src;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	//試してみる、2回ベースクラスのコピーコンストラクターを読んだでは？
	if (this != &other)
	{
		std::cout << "<ShrubberyCreationForm> Copy assignment operator is called" << std::endl;
		target_ = other.getTarget();
		AForm::operator=(other);
	}
	return *this;
}

std::string ShrubberyCreationForm::getTarget() const
{
	return target_;
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	if (!this->getIsSigned())
		throwCommonException("the form is unsigned!\n");
	else if (executor.getGrade() > this->getExecuteGrade())
		throwCommonException("the bureaucrat's execute grade is not enough to execute the form\n");
	else
	{
		std::ofstream outfile((this->getTarget() + "_shrubbery").c_str(), std::ofstream::out);
		if (!outfile.is_open())
			throwCommonException("Unable to create" + this->getTarget() + "_shrubbery file\n");
		else
		{
			outfile << "               ,@@@@@@@," << std::endl;
			outfile << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
			outfile << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl;
			outfile << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
			outfile << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
			outfile << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
			outfile << "   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
			outfile << "       |o|        | |         | |" << std::endl;
			outfile << "       |.|        | |         | |" << std::endl;
			outfile << "/_-/\\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_" << std::endl;
			outfile.close();
		}
	}
}