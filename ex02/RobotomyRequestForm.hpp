
#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <string>
#include <iostream>
#include <cstdlib>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm;


class RobotomyRequestForm : public AForm
{
		const std::string	target;
		RobotomyRequestForm();
	public:
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm &copy);
		RobotomyRequestForm &operator=(RobotomyRequestForm &copy);
		~RobotomyRequestForm();

		std::string	getTarget(void)const;
		void		execute(Bureaucrat const &executor) const;
};

std::ostream	&operator<<(std::ostream &os, RobotomyRequestForm *a);

#endif