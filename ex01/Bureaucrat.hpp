/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-wits <bde-wits@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 08:32:09 by bde-wits          #+#    #+#             */
/*   Updated: 2025/02/26 02:50:43 by bde-wits         ###   ########.fr       */
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
#include "Form.hpp"
class Form;

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
		int getGrade();
		void	incremental_grade();
		void	decremental_grade();
		void	signForm(Form& form);//
	private:
		const std::string	name;
		int 		Grade;
};
	
std::ostream& operator<<(std::ostream& out, Bureaucrat& b);
// #endif