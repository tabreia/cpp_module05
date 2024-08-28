#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm;

class ShrubberyCreationForm : public AForm
{
	const std::string	target;
	ShrubberyCreationForm();
public:
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(ShrubberyCreationForm &copy);
	ShrubberyCreationForm &operator=(ShrubberyCreationForm const &copy);
	~ShrubberyCreationForm();

	std::string	getTarget(void)const;
	void		execute(Bureaucrat const &executor)const;
};

std::ostream	&operator<<(std::ostream &os, ShrubberyCreationForm *a);

#endif