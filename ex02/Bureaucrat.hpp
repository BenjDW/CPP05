/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-wits <bde-wits@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 08:32:09 by bde-wits          #+#    #+#             */
/*   Updated: 2025/02/12 02:17:28 by bde-wits         ###   ########.fr       */
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
class Form;

class GradeTooHighException : public std::exception
{
		public:
			const char* what() const noexcept 
			{
				return "Grade Too High !";
			}
};

class GradeTooLowException : public std::exception
{
	public:
		const char* what() const noexcept 
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
		std::int32_t getGrade();
		void	incremental_grade();
		void	decremental_grade();
		void	signForm(Form& form);//
		void 	executeForm(Form const & form);
	private:
		const std::string	name;
		std::int32_t 		Grade;
};
	
std::ostream& operator<<(std::ostream& out, Bureaucrat& b);
// #endif