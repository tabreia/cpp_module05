/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabreia- <tabreia-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:46:18 by tabreia-          #+#    #+#             */
/*   Updated: 2023/09/22 16:46:18 by tabreia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : name("default"), isSigned(false), gradeSign(150), gradeExec(150)
{
	std::cout << "Form default constructor called" << std::endl;
}

AForm::AForm(int gradeSign, int gradeExec) : name("default"), isSigned(false), gradeSign(gradeSign), gradeExec(gradeExec)
{
	std::cout << "Form constructor called for " << this->name << " with sign grade of " <<
	gradeSign << " and execution grade of " << gradeExec <<  std::endl;
	if (this->getGradeSign() > 150 || this->getGradeExec() > 150)
		throw (AForm::GradeTooLowException());
	else if (this->getGradeSign() < 1 || this->getGradeExec() < 1)
		throw (AForm::GradeTooHighException());
}

AForm::AForm(std::string name) : name(name), isSigned(false), gradeSign(150), gradeExec(150)
{
	std::cout << "Form constructor called for " << this->name << " with sign grade of " <<
	this->gradeSign << " and execution grade of " << this->gradeExec <<  std::endl;
}

AForm::AForm(std::string const name, int gradeSign, int gradeExec) : name(name), isSigned(false), gradeSign(gradeSign), gradeExec(gradeExec)
{
	std::cout << "Form constructor called for " << this->name << " with sign grade of " <<
			  gradeSign << " and execution grade of " << gradeExec <<  std::endl;
	if (this->getGradeSign() > 150 || this->getGradeExec() > 150)
		throw (AForm::GradeTooLowException());
	else if (this->getGradeSign() < 1 || this->getGradeExec() < 1)
		throw (AForm::GradeTooHighException());
}

AForm::AForm(const AForm &copy) : name(copy.getName() + "_copy"), isSigned(false), gradeSign(copy.getGradeSign()), gradeExec(copy.getGradeExec())
{
	std::cout << "Form copy constructor called" << std::endl;
	*this = copy;
}

AForm &AForm::operator=(const AForm &copy)
{
	if (this == &copy)
		return *this;
	return *this;
}

AForm::~AForm()
{
	std::cout << "Form Deconstructor for " << this->getName() << " called" << std::endl;
}

const std::string AForm::getName() const
{
	return (this->name);
}

bool AForm::getIsSigned() const
{
	return (this->isSigned);
}

int AForm::getGradeSign() const
{
	return (this->gradeSign);
}

int AForm::getGradeExec() const
{
	return (this->gradeExec);
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->getGradeSign())
		this->isSigned = true;
	bureaucrat.signForm(*this);
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high!!");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low!!");
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return ("Form needs to be signed in order to be executed");
}

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
	if (form.getIsSigned())
	{
		os << form.getName() << ", form signed status true";
		os << ", required grade to sign this form is " << form.getGradeSign();
		os << ", required grade to execute this form is " << form.getGradeExec() << std::endl;
	}
	else
	{
		os << form.getName() << ", form signed status false";
		os << ", required grade to sign this form is " << form.getGradeSign();
		os << ", required grade to execute this form is " << form.getGradeExec() << std::endl;
	}
	return (os);
}