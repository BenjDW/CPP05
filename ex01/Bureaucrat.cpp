/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-wits <bde-wits@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 08:32:06 by bde-wits          #+#    #+#             */
/*   Updated: 2025/03/03 13:19:45 by bde-wits         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void	Bureaucrat::signForm(Form& form)
{
	try 
	{
		form.beSigned(*this);
			std::cout << this->name << " signed " << form.getName() << std::endl;
	} 
	catch (const std::exception& e) 
	{
		std::cout << this->name << " couldn’t sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

std::ostream&	operator<<(std::ostream& out, Bureaucrat& b)
{
	out << b.getName() << ", bureaucrat grade " << b.getGrade() << "." << std::endl;
	return (out);
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat cpy)
{
	this->Grade = cpy.Grade;
	return *this;
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

int	Bureaucrat::getGrade()
{
	return (this->Grade);
}

Bureaucrat::Bureaucrat() : name ("bobby"), Grade (10)
{
	// this->Grade = 10;
}

Bureaucrat::Bureaucrat(int lvl) : name ("ansar_tek"), Grade (lvl)
{
	// Grade = lvl;
	if (Grade < 1)
		throw (GradeTooHighException());
	if (Grade > 150)
		throw (GradeTooLowException());
}

Bureaucrat::Bureaucrat(Bureaucrat &cpy) : Grade (cpy.Grade)
{
	// Grade = cpy.Grade;
}

Bureaucrat::~Bureaucrat()
{
}