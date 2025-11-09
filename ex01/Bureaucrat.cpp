/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 15:42:30 by ysumeral          #+#    #+#             */
/*   Updated: 2025/11/09 17:15:36 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
	std::cout << "Bureaucrat " << this->_name << " constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	this->_name = name;
	this->_grade = grade;
	std::cout << "Bureaucrat " << this->_name << " constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &ref)
{
	this->_name = ref._name;
	this->_grade = ref._grade;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &ref)
{
	if (this != &ref)
	{
		this->_name = ref._name;
		this->_grade = ref._grade;
	}
	return (*this);
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return (os);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat " << this->_name << " destructor called" << std::endl;
}

std::string Bureaucrat::getName() const
{
	return (this->_name);
}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void Bureaucrat::incrementGrade()
{
	int grade;

	grade = getGrade();
	if (grade - 1 < 1)
		throw GradeTooHighException();
	this->_grade--;
	std::cout << "Grade Increment -> Updated " << getName() << " grade is: "
		<< getGrade() << std::endl;
}

void	Bureaucrat::decrementGrade()
{
	int grade;

	grade = getGrade();
	if (grade + 1 > 150)
		throw GradeTooLowException();
	this->_grade++;
	std::cout << "Grade Descrement -> Updated " << getName() << " grade is: "
		<< getGrade() << std::endl;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high! Where else do you want to go?");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low! Where else will you fall?");
}