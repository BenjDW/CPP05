/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-wits <bde-wits@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 08:32:09 by bde-wits          #+#    #+#             */
/*   Updated: 2025/02/11 07:43:23 by bde-wits         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <ostream>
#include <iomanip>
#include <string>
#include <exception>

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
	private:
		const std::string	name;
		std::int32_t 		Grade;
};
	
std::ostream& operator<<(std::ostream& out, Bureaucrat& b);

#endif