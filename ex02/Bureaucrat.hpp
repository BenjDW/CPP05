/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-wits <bde-wits@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 08:32:09 by bde-wits          #+#    #+#             */
/*   Updated: 2025/02/26 07:56:52 by bde-wits         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #ifndef BUREAUCRAT_HPP
// # define BUREAUCRAT_HPP
#pragma once

#include <iostream>
#include <ostream>
#include <iomanip>
#include <string>
#include <exception>
#include "AForm.hpp"
class AForm;

class GradeTooHighException : public std::exception
{
		public:
			const char* what() const throw() 
			{
				return "Grade Too High !";
			}
};

class GradeTooLowException : public std::exception
{
	public:
		const char* what() const throw()
		{
			return "Grade Too Low !";
		}
};

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(int lvl);
		Bureaucrat(Bureaucrat& cpy);
		~Bureaucrat();
		std::string	getName();
		int getGrade() const;
		void	incremental_grade();
		void	decremental_grade();
		void	signForm(AForm& AForm);//
		void 	executeForm(AForm const &AForm);
		Bureaucrat	&operator=(Bureaucrat cpy);
	private:
		const std::string	name;
		int 		Grade;
};

// Lastly, add the executeForm(AForm const & AForm) member function to the Bureaucrat.
//It must attempt to execute the AForm. If it’s successful, print something like:
// <bureaucrat> executed <AForm>
// If not, print an explicit error message.
// Implement and turn in some tests to ensure everything works as expected.

// void	Bureaucrat::executeForm(AForm const &AForm)
// {
// 	try 
// 	{
// 		AForm.execute(*this);
// 		std::cout << this->getName() << " executed " << AForm.getGrade() << std::endl;
// 	} 
// 	catch (const std::exception &e)
// 	{
// 		std::cerr << this->getName() << " couldn't execute " << AForm.getName()
// 		          << " because " << e.what() << std::endl;
// 	}
// }

std::ostream& operator<<(std::ostream& out, Bureaucrat& b);
// #endif