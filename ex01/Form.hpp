/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-wits <bde-wits@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:54:54 by bde-wits          #+#    #+#             */
/*   Updated: 2025/02/11 10:31:30 by bde-wits         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #ifndef FORM_HPP
// # define FORM_HPP
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
		Form(Form &cpy); // return copie du contenue
		~Form();
		void			beSigned(Bureaucrat& agent);
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