/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-wits <bde-wits@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:54:54 by bde-wits          #+#    #+#             */
/*   Updated: 2025/02/12 02:35:28 by bde-wits         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #ifndef AFORM_HPP
// # define AFORM_HPP
#pragma once
#include <iostream>
#include <ostream>
#include <iomanip>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"
class Bureaucrat;

class AlreadySignedException : public std::exception
{
    public:
        const char* what() const noexcept
		{
			return "already signed";
		};
};

class Form
{
	public:
		Form();
		Form(const std::string named);
		Form(const std::string named, int32_t grad, int32_t grad_ex);// polymorphisme
		Form(Form &cpy); // return copie du contenue
		~Form();
		void			beSigned(Bureaucrat& agent); 
		virtual const void	execute(Bureaucrat const &executor) = 0;
		//passe la fonction en heritage et abstraite force de la reimplemente dans les class dérive
		const int32_t	getGrade();
		bool			getSigne();
		std::string		getName();
		const int32_t	getGrade_exec();
	private:
		std::string 	name;//name of the form
		bool			signe;//are form signed ?
		const int32_t	grade;//lvl required sign
		const int32_t	grade_exec;//lvl required for execute the form
};

std::ostream&	operator<<(std::ostream& out, Form& f);

// #endif