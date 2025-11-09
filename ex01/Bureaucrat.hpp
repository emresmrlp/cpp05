/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 15:42:28 by ysumeral          #+#    #+#             */
/*   Updated: 2025/11/09 17:15:29 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include <string>

class Bureaucrat
{
public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &ref);
	Bureaucrat &operator=(const Bureaucrat &ref);
	~Bureaucrat();
	class		GradeTooHighException;
	class		GradeTooLowException;
	std::string	getName() const;
	int			getGrade() const;
	void		incrementGrade();
	void		decrementGrade();
private:
	std::string	_name;
	int			_grade;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

class Bureaucrat::GradeTooHighException : public std::exception
{
public:
	virtual const char *what() const throw();
};

class Bureaucrat::GradeTooLowException : public std::exception
{
public:
	virtual const char *what() const throw();
};

#endif