/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-wits <bde-wits@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 08:32:09 by bde-wits          #+#    #+#             */
/*   Updated: 2025/02/07 08:56:48 by bde-wits         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ostream>
#include <iomanip>
#include <string>

// First, start by the smallest cog in this vast bureaucratic machine: the Bureaucrat.
// A Bureaucrat must have:
// • A constant name.
// • And a grade that ranges from 1 (highest possible grade) to 150 (lowest possible
// grade).
// Any attempt to instantiate a Bureaucrat using an invalid grade must throw an exception:
// either a Bureaucrat::GradeTooHighException or a Bureaucrat::GradeTooLowException

// try
// {
// /* do some stuff with bureaucrats */
// }
// catch (std::exception & e)
// {
// /* handle exception */
// }

class bureaucrat
{
	public:
		bureaucrat(/* args */);
		bureaucrat(int lvl);
		bureaucrat(bureaucrat& cpy);
		~bureaucrat();
		std::string	getName();
		std::int32_t getGrade();
		void	incremental_grade();
		void	decremental_grade();
		// bureaucrat &operator<<(); //  insertion («) operator to print something like (without the angle brackets):
		std::exception GradeTooHighException();
		std::exception GradeTooLowException();
	private:
		const std::string	name;
		std::int32_t 		Grade;
};

std::exception bureaucrat::GradeTooHighException()
{
	if (this->Grade < 1)
		return (std::exception());
}

std::exception bureaucrat::GradeTooLowException()
{
	if (this->Grade > 150)
		return (std::exception());
}

void	bureaucrat::incremental_grade()
{
	Grade -= 1;
	try
	{
		bureaucrat::GradeTooHighException();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

void	bureaucrat::decremental_grade()
{
	Grade += 1;
	try
	{
		bureaucrat::GradeTooLowException();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

std::string	bureaucrat::getName()
{
	return (this->name);
}

std::int32_t	bureaucrat::getGrade()
{
	return (this->Grade);
}

bureaucrat::bureaucrat()
{
	Grade = 10;
}

bureaucrat::bureaucrat(int lvl)
{
	Grade = lvl;
	// try
	// {
	// 	bureaucrat::GradeTooHighException();
	// 	bureaucrat::GradeTooLowException();
	// }
}

// return a copie du contenue de l'objet envoyer
bureaucrat::bureaucrat(bureaucrat &cpy)
{
	Grade = cpy.Grade;
}

bureaucrat::~bureaucrat()
{
}
