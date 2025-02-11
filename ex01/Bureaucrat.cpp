/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-wits <bde-wits@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 08:32:06 by bde-wits          #+#    #+#             */
/*   Updated: 2025/02/11 07:33:40 by bde-wits         ###   ########.fr       */
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

void	Bureaucrat::incremental_grade()
{
	Grade -= 1;
	if (this->Grade < 1)
		throw (GradeTooHighException());
	// try
	// {
	// 	GradeTooHighException();
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
	
}

void	Bureaucrat::decremental_grade()
{
	Grade += 1;
	if (this->Grade > 150)
		throw (GradeTooLowException());
	// try
	// {
	// 	Bureaucrat::GradeTooLowException();
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
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
	// this->name = "Bobby";
	this->Grade = 10;
}

Bureaucrat::Bureaucrat(int lvl) : name ("ansar_tek")
{
	Grade = lvl;
	if (Grade < 1)
		throw (GradeTooHighException());
	if (Grade > 150)
		throw (GradeTooLowException());
	// try
	// {
	// 	bureaucrat::GradeTooHighException();
	// 	bureaucrat::GradeTooLowException();
	// }
}

// return a copie du contenue de l'objet envoyer
Bureaucrat::Bureaucrat(Bureaucrat &cpy)
{
	Grade = cpy.Grade;
}

Bureaucrat::~Bureaucrat()
{
}