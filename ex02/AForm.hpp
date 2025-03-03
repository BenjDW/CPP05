/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-wits <bde-wits@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:54:54 by bde-wits          #+#    #+#             */
/*   Updated: 2025/03/03 13:22:00 by bde-wits         ###   ########.fr       */
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
        const char* what() const throw()
		{
			return "already signed";
		};
};

class AForm
{
	public:
		AForm();
		AForm(const std::string named, int grad, int grad_ex);
		AForm(AForm &cpy);
		virtual	~AForm();
		void			beSigned(Bureaucrat& agent); 
		virtual void	execute(Bureaucrat const &agen) const = 0;
		int	getGrade() const;
		bool			getSigne() const;
		std::string		getName() const;
		int	getGrade_exec() const;
		AForm &operator=(AForm const &cpy);
	private:
		std::string 	name;
		bool			signe;
		const int	grade;
		const int	grade_exec;
};

std::ostream&	operator<<(std::ostream& out, AForm& f);

// #endif