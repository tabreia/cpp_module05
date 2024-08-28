/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabreia- <tabreia-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:46:18 by tabreia-          #+#    #+#             */
/*   Updated: 2023/09/22 16:46:18 by tabreia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	protected:
		std::string	name;
		bool		isSigned;
		int			gradeSign;
		int			gradeExec;

		AForm();
		AForm(int gradeSign, int gradeExec);
		AForm(std::string const name);
		AForm(std::string const name, int gradeSign, int gradeExec);
	public:
		AForm(AForm const &copy);
		AForm &operator=(AForm const &copy);
		virtual ~AForm();

		const std::string			getName() const;
		bool				getIsSigned() const;
		int					getGradeSign() const;
		int					getGradeExec() const;
		void				beSigned(Bureaucrat &bureaucrat);
		virtual void		execute(Bureaucrat const &executor) const = 0;

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif