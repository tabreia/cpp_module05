/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabreia- <tabreia-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:10:12 by tabreia-          #+#    #+#             */
/*   Updated: 2023/10/02 15:10:12 by tabreia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
	std::cout << "Intern constructor called" << std::endl;
}

Intern::~Intern()
{
	std::cout << "Intern deconstructor called" << std::endl;
}

Intern::Intern(Intern &copy)
{
	(void)copy;
	std::cout << "Intern copy constructor called" << std::endl;
}

Intern &Intern::operator=(Intern &copy)
{
	return(copy);
}

AForm *Intern::makeForm(std::string name, std::string target)
{
	AForm			*ret;
	int 			index = -1;
	std::string     forms[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};

	for (int i = 0; i < (int)name.length(); ++i)
	{
		name[i] = tolower(name[i]);
	}
	for (int i = 0; i < 3; ++i)
	{
		if (name == forms[i])
			index = i;
	}
	switch (index)
	{
		case 0:
		{
			ret = new PresidentialPardonForm(target);
			return (ret);
		}
		case 1:
		{
			ret = new RobotomyRequestForm(target);
			return (ret);
		}
		case 2:
		{
			ret = new ShrubberyCreationForm(target);
			return (ret);
		}
		default:
		{
			std::cout << "Invalid Form name" << std::endl;
			return (0);
		}
	}
}