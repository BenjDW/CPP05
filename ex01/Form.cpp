/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-wits <bde-wits@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 06:09:16 by bde-wits          #+#    #+#             */
/*   Updated: 2025/02/11 08:30:13 by bde-wits         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

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

bool	Form::getSigne()
{
	return (this->signe);
}

std::string	Form::getName()
{
	return (this->name);
}

const int32_t	Form::getGrade_exec()
{
	return (this->grade_exec);
}

const int32_t	Form::getGrade()
{
	return (this->grade);
}

Form::Form() : name ("Triple The Tax"), signe (false), grade (11), grade_exec (12)
{
	if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

Form::Form(const std::string named) : signe (false), grade (11), grade_exec (12)
{
	this->name = named;
	if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

Form::Form(Form &cpy) : signe (cpy.signe), grade(cpy.grade), grade_exec (cpy.grade_exec), name (cpy.name)
{
}

Form::~Form()
{
}
