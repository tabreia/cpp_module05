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
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void	testPresidential()
{
	std::cout << "###### Testing PresidentialPardonForm ######" << std::endl;
	std::cout << std::endl;
	std::cout << "------Trying to sign with a low grade------" << std::endl;
	Bureaucrat	*a = new Bureaucrat();
	AForm		*form1 = new PresidentialPardonForm("default");

	std::cout << std::endl;
	std::cout << *a;
	std::cout << std::endl;
	std::cout << *form1;
	std::cout << std::endl;
	try
	{
		form1->beSigned(*a);
	}
	catch(std::exception &e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;
	delete a;
	delete form1;
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "------Trying to execute without signing------" << std::endl;
	std::cout << std::endl;
	Bureaucrat	*assistant = new Bureaucrat("Assistant", 145);
	Bureaucrat	*ceo = new Bureaucrat("CEO", 1);
	AForm		*form = new PresidentialPardonForm("someone");

	std::cout << *assistant;
	std::cout << *ceo;
	std::cout << *form;
	std::cout << std::endl;
	try
	{
		form->execute(*ceo);
	}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;
	std::cout << "---Assistant signs the form---" << std::endl;
	try
	{
		form->beSigned(*assistant);
	}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;
	std::cout << "---CEO signs the form---" << std::endl;
	try
	{
		form->beSigned(*ceo);
	}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;
	std::cout << "---CEO executes the form---" << std::endl;
	try
	{
		form->execute(*ceo);
	}
	catch(std::exception &e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;
	delete assistant;
	delete ceo;
	delete form;
	std::cout << std::endl;
	std::cout << std::endl;
}

void	testRobotomy()
{
	std::cout << "###### Testing RobotomyRequestForm ######" << std::endl;
	std::cout << std::endl;
	std::cout << "------Trying to sign with a low grade------" << std::endl;
	Bureaucrat	*a = new Bureaucrat();
	AForm		*form1 = new RobotomyRequestForm("default");

	std::cout << std::endl;
	std::cout << *a;
	std::cout << std::endl;
	std::cout << *form1;
	std::cout << std::endl;
	try
	{
		form1->beSigned(*a);
	}
	catch(std::exception &e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;
	delete a;
	delete form1;
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "------Trying to execute without signing------" << std::endl;

	std::cout << std::endl;
	Bureaucrat	*assistant = new Bureaucrat("Assistant", 145);
	Bureaucrat	*ceo = new Bureaucrat("CEO", 1);
	AForm		*form = new RobotomyRequestForm("someone");

	std::cout << *assistant;
	std::cout << *ceo;
	std::cout << *form;
	std::cout << std::endl;
	try
	{
		form->execute(*ceo);
	}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;
	std::cout << "---Assistant signs the form---" << std::endl;
	try
	{
		form->beSigned(*assistant);
	}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;
	std::cout << "---CEO signs the form---" << std::endl;
	try
	{
		form->beSigned(*ceo);
	}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;
	std::cout << "---CEO executes the form four times---" << std::endl;
	try
	{
		form->execute(*ceo);
	}
	catch(std::exception &e)
	{
		std::cout << e.what();
	}
	try
	{
		form->execute(*ceo);
	}
	catch(std::exception &e)
	{
		std::cout << e.what();
	}
	try
	{
		form->execute(*ceo);
	}
	catch(std::exception &e)
	{
		std::cout << e.what();
	}
	try
	{
		form->execute(*ceo);
	}
	catch(std::exception &e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;
	delete assistant;
	delete ceo;
	delete form;
	std::cout << std::endl;
	std::cout << std::endl;
}

void	testShrubbery()
{
	std::cout << "###### Testing ShrubberyCreationForm ######" << std::endl;
	std::cout << std::endl;

	std::cout << "------Trying to sign with a low grade------" << std::endl;
	Bureaucrat	*a = new Bureaucrat();
	AForm		*form1 = new ShrubberyCreationForm("default");

	std::cout << std::endl;
	std::cout << *a;
	std::cout << std::endl;
	std::cout << *form1;
	std::cout << std::endl;
	try
	{
		form1->beSigned(*a);
	}
	catch(std::exception &e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;
	delete a;
	delete form1;
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "------Trying to execute without signing------" << std::endl;

	std::cout << std::endl;
	Bureaucrat	*assistant = new Bureaucrat("Assistant", 145);
	Bureaucrat	*ceo = new Bureaucrat("CEO", 1);
	AForm		*form = new ShrubberyCreationForm("someone");

	std::cout << *assistant;
	std::cout << *ceo;
	std::cout << *form;
	std::cout << std::endl;
	try
	{
		form->execute(*ceo);
	}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;
	std::cout << "---Assistant signs the form---" << std::endl;
	try
	{
		form->beSigned(*assistant);
	}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;
	std::cout << "---CEO signs the form---" << std::endl;
	try
	{
		form->beSigned(*ceo);
	}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;
	std::cout << "---CEO executes the form---" << std::endl;
	try
	{
		form->execute(*ceo);
	}
	catch(std::exception &e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;
	delete assistant;
	delete ceo;
	delete form;
	std::cout << std::endl;
	std::cout << std::endl;
}

int main(void)
{
	testPresidential();
	testRobotomy();
	testShrubbery();
}