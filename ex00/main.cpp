/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 15:37:32 by ysumeral          #+#    #+#             */
/*   Updated: 2025/11/09 17:18:02 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat *bureaucrat = NULL;
	try
	{
		bureaucrat = new Bureaucrat("Emre", 1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	if (bureaucrat)
	{
		std::cout << *bureaucrat << std::endl;
		try
		{
			bureaucrat->incrementGrade();
			std::cout << *bureaucrat << std::endl;
			bureaucrat->decrementGrade();
			std::cout << *bureaucrat << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		delete (bureaucrat);
	}
	return (0);
}