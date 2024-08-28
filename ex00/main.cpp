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

int main(void)
{
	Bureaucrat	highGrade("lala", 1);
	Bureaucrat	lowGrade("fafafa", 150);

	std::cout << "### HIGH GRADE OVERLOAD ###" << std::endl;
	try
	{
		std::cout << highGrade;
		highGrade.decrementGrade();
		std::cout << highGrade;
		highGrade.incrementGrade();
		highGrade.incrementGrade();
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "### LOW GRADE OVERLOAD ###" << std::endl;
	try
	{
		std::cout << lowGrade;
		lowGrade.incrementGrade();
		std::cout << lowGrade;
		lowGrade.decrementGrade();
		lowGrade.decrementGrade();
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "### TESTS FINISHED ###" << std::endl;
}