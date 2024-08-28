

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("default")
{
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), target(target)
{
	std::cout << "RobotomyRequestForm for " << this->getTarget() << " called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &copy) : AForm("RobotomyRequestForm", 72, 45), target(copy.getTarget())
{
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
	*this = copy;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm &copy)
{
	if (this == &copy)
		return *this;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm deconstructor for " << this->getName() << " called" << std::endl;
}

std::string RobotomyRequestForm::getTarget() const
{
	return (this->target);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	static int fail = 0;

	if (executor.getGrade() > this->getGradeExec())
		throw (Bureaucrat::GradeTooLowException());
	else if (!this->getIsSigned())
		throw (AForm::FormNotSignedException());
	else if (fail++ % 2)
		std::cout << this->getTarget() << " has been robotomized" << std::endl;
	else
		std::cout << "Robotomy failed" << std::endl;

}

std::ostream &operator<<(std::ostream &os, RobotomyRequestForm *a)
{
	if (a->getIsSigned())
	{
		os << "Form name: " << a->getName() << "\nSign grade: " <<
		   a->getGradeSign() << "\nExec grade: " << a->getGradeExec() <<
		   "\nIs signed: True";
	}
	else
	{
		os << "Form name: " << a->getName() << "\nSign grade: " <<
		   a->getGradeSign() << "\nExec grade: " << a->getGradeExec() <<
		   "\nIs signed: False";
	}
	return (os);
}
