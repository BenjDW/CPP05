/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-wits <bde-wits@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 08:32:06 by bde-wits          #+#    #+#             */
/*   Updated: 2025/02/11 07:42:39 by bde-wits         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

std::ostream&	operator<<(std::ostream& out, Bureaucrat& b)
{
	out << b.getName() << ", bureaucrat grade " << b.getGrade() << "." << std::endl;
	return (out);
}

void	Bureaucrat::incremental_grade()
{
	Grade -= 1;
	if (this->Grade < 1)
		throw (GradeTooHighException());
}

void	Bureaucrat::decremental_grade()
{
	Grade += 1;
	if (this->Grade > 150)
		throw (GradeTooLowException());
}

std::string	Bureaucrat::getName()
{
	return (this->name);
}

std::int32_t	Bureaucrat::getGrade()
{
	return (this->Grade);
}

Bureaucrat::Bureaucrat() : name ("bobby")
{
	this->Grade = 10;
}

Bureaucrat::Bureaucrat(int lvl) : name ("ansar_tek")
{
	Grade = lvl;
	if (Grade < 1)
		throw (GradeTooHighException());
	if (Grade > 150)
		throw (GradeTooLowException());
}

Bureaucrat::Bureaucrat(Bureaucrat &cpy)
{
	Grade = cpy.Grade;
}

Bureaucrat::~Bureaucrat()
{
}