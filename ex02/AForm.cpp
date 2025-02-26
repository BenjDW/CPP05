/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-wits <bde-wits@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 06:09:16 by bde-wits          #+#    #+#             */
/*   Updated: 2025/02/26 03:08:15 by bde-wits         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

std::ostream&	operator<<(std::ostream& out, Form& f)
{
	out << f.getName() << " Form , Form grade " << f.getGrade() << ", Form grade execution " << f.getGrade_exec() << std::endl;
	return (out);
}

void	Form::beSigned(Bureaucrat& agent)
{
	if (agent.getGrade() < 1)
		throw(GradeTooHighException());
	else if (agent.getGrade() > 150 || agent.getGrade() > this->grade)
		throw(GradeTooLowException());
	else if (this->signe == false)
		this->signe = true;
	else
		throw(AlreadySignedException());
}

bool	Form::getSigne() const
{
	return (this->signe);
}

std::string	Form::getName() const
{
	return (this->name);
}

int	Form::getGrade_exec() const
{
	return (this->grade_exec);
}

int	Form::getGrade() const
{
	return (this->grade);
}

Form& Form::operator=(Form const &cpy)
{
	this->name = cpy.getName();
	this->signe = cpy.getSigne();
	return *this;
}

Form::Form() : name ("Triple The Tax"), signe (false), grade (11), grade_exec (12)
{
	if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

Form::Form(const std::string named, int grad, int grad_ex) : signe (false), grade (grad), grade_exec (grad_ex)
{
	this->name = named;
	if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

Form::Form(Form &cpy) : name(cpy.name), signe(cpy.signe), grade(cpy.grade), grade_exec(cpy.grade_exec)
{
}

Form::~Form()
{
}
