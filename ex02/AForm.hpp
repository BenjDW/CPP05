/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-wits <bde-wits@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:54:54 by bde-wits          #+#    #+#             */
/*   Updated: 2025/02/25 10:52:43 by bde-wits         ###   ########.fr       */
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
#include <fstream>
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
		Form(const std::string named, int32_t grad, int32_t grad_ex);// polymorphisme
		Form(Form &cpy); // return copie du contenue
		virtual	~Form();
		void			beSigned(Bureaucrat& agent); 
		//passe la fonction en heritage et abstraite force de la reimplemente dans les class dérive
		virtual void	execute(Bureaucrat const &agen) const = 0;
		int32_t	getGrade() const;
		bool			getSigne() const;
		std::string		getName() const;
		int32_t	getGrade_exec() const;
	private:
		std::string 	name;//name of the form
		bool			signe;//are form signed ?
		const int32_t	grade;//lvl required sign
		const int32_t	grade_exec;//lvl required for execute the form
};

std::ostream&	operator<<(std::ostream& out, Form& f);

// void	Form::execute(Bureaucrat const &agent) const
// {
// 	if (this->getSigne() != true)
// 		throw (NotSignedForm());
// 	if (this->getGrade() > this->getGrade_exec())
// 		throw (GradeTooLowException());
// 	std::cout << "Informs that " << this->name << " Form has been execute." << std::endl;
// }

// #endif