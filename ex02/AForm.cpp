/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-wits <bde-wits@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 06:09:16 by bde-wits          #+#    #+#             */
/*   Updated: 2025/02/26 07:56:49 by bde-wits         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

std::ostream&	operator<<(std::ostream& out, AForm& f)
{
	out << f.getName() << " AForm , AForm grade " << f.getGrade() << ", AForm grade execution " << f.getGrade_exec() << std::endl;
	return (out);
}

void	AForm::beSigned(Bureaucrat& agent)
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

bool	AForm::getSigne() const
{
	return (this->signe);
}

std::string	AForm::getName() const
{
	return (this->name);
}

int	AForm::getGrade_exec() const
{
	return (this->grade_exec);
}

int	AForm::getGrade() const
{
	return (this->grade);
}

AForm& AForm::operator=(AForm const &cpy)
{
	this->name = cpy.getName();
	this->signe = cpy.getSigne();
	return *this;
}

AForm::AForm() : name ("Triple The Tax"), signe (false), grade (11), grade_exec (12)
{
	if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

AForm::AForm(const std::string named, int grad, int grad_ex) : signe (false), grade (grad), grade_exec (grad_ex)
{
	this->name = named;
	if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

AForm::AForm(AForm &cpy) : name(cpy.name), signe(cpy.signe), grade(cpy.grade), grade_exec(cpy.grade_exec)
{
}

AForm::~AForm()
{
}
