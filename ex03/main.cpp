/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabreia- <tabreia-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:27:23 by tabreia-          #+#    #+#             */
/*   Updated: 2023/09/22 16:27:23 by tabreia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main(void)
{
	Intern	testIntern;
	AForm	*rrf;
	AForm	*ppf;
	AForm	*scf;
	AForm	*test;

	std::cout << std::endl;
	std::cout << "------Creating RobotomyRequestForm------" << std::endl;
	rrf = testIntern.makeForm("robotomy request", "Bender");
	delete rrf;
	std::cout << std::endl;
	std::cout << "------Creating PresidentialPardonForm------" << std::endl;
	ppf = testIntern.makeForm("presidential pardon", "some one");
	delete ppf;
	std::cout << std::endl;
	std::cout << "------Creating ShrubberyCreationForm------" << std::endl;
	scf = testIntern.makeForm("shrubbery creation", "someone else");
	delete scf;
	std::cout << std::endl;
	std::cout << "------Creating an invalid form------" << std::endl;
	test = testIntern.makeForm("this form doesnt exist", "default");
	delete test;
	return (0);
}