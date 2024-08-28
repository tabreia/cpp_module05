/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabreia- <tabreia-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:46:18 by tabreia-          #+#    #+#             */
/*   Updated: 2023/09/22 16:46:18 by tabreia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : isSigned(false), gradeSign(0), gradeExec(0)
{

}

Form::Form(std::string const &name, const int gradeSign, const int gradeExec)
{
	this->name = name;
	this->isSigned = false;
	if (gradeSign < 1)
		throw Form::GradeTooHighException();
	if (gradeSign > 150)
		throw Form::GradeTooLowException();
	this->gradeSign = gradeSign;
	if (gradeExec < 1)
		throw Form::GradeTooHighException();
	if (gradeExec > 150)
		throw Form::GradeTooLowException();
	this->gradeExec = gradeExec;
}

Form::Form(const Form &copy)
{
	this->name = copy.name;
	this->isSigned = copy.isSigned;
	this->gradeSign = copy.gradeSign;
	this->gradeExec = copy.gradeExec;
}

Form &Form::operator=(const Form &copy)
{
	this->name = copy.name;
	this->isSigned = copy.isSigned;
	this->gradeSign = copy.gradeSign;
	this->gradeExec = copy.gradeExec;
	return (*this);
}

Form::~Form()
{

}

std::string Form::getName() const
{
	return (this->name);
}

bool Form::getIsSigned() const
{
	return (this->isSigned);
}

int Form::getGradeSign() const
{
	return (this->gradeSign);
}

int Form::getGradeExec() const
{
	return (this->gradeExec);
}

void Form::beSigned(Bureaucrat bureaucrat)
{
	if (bureaucrat.getGrade() <= this->gradeSign)
		this->isSigned = true;
	bureaucrat.signForm(*this);
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high!!");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low!!");
}

std::ostream& operator<<(std::ostream& os, const Form& form)
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