/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabreia- <tabreia-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 14:09:56 by tabreia-          #+#    #+#             */
/*   Updated: 2023/09/22 14:09:56 by tabreia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(150)
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const &name, int grade) : name(name)
{
	std::cout << "Bureaucrat Constructor called for " << this->getName() <<
			  " with grade of " << grade << std::endl;
	try
	{
		this->setGrade(grade);
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		this->setGrade(1);
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		this->setGrade(150);
	}
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy) : name(copy.getName() + "_copy")
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	*this = copy;
}

Bureaucrat::Bureaucrat(int grade) : name("default")
{
	std::cout << "Bureaucrat Constructor called for " << this->getName() <<
			  " with grade of " << grade << std::endl;
	try
	{
		this->setGrade(grade);
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		this->setGrade(1);
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{

		this->setGrade(150);
	}
}

Bureaucrat::Bureaucrat(const std::string &name) : name(name), grade(150)
{
	std::cout << "Bureaucrat Constructor called for " << this->getName() <<
			  " with grade of " << this->getGrade() << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat deconstructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy)
{
	if (this == &copy)
		return *this;
	this->grade = copy.getGrade();
	return *this;
}

std::string Bureaucrat::getName() const
{
	return (this->name);
}

int Bureaucrat::getGrade() const
{
	return (this->grade);
}

void Bureaucrat::incrementGrade()
{
	try
	{
		this->setGrade(this->grade - 1);
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cout << "\033[33mIncrementing grade of " << this->getName() <<
				  " failed: " << e.what() << "\033[0m" << std::endl;
	}
}

void Bureaucrat::decrementGrade()
{
	try
	{
		this->setGrade(this->grade + 1);
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cout << "\033[33mDecrementing grade of " << this->getName() <<
				  " failed: " << e.what() << "\033[0m" << std::endl;
	}
}

void Bureaucrat::signForm(AForm &form)
{
	if (!form.getIsSigned())
	{
		std::cout << this->name << " couldn't sign " << form.getName() << " because";
		std::cout << " grade was too low" << std::endl;
		return ;
	}
	std::cout << this->name << " signed " << form.getName() << std::endl;
}

void	Bureaucrat::setGrade(int grade)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->grade = grade;
}


void Bureaucrat::executeForm(AForm &form) const
{
	form.execute(*this);
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high!!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low!!");
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
	return (os);
}
