/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-wits <bde-wits@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:54:54 by bde-wits          #+#    #+#             */
/*   Updated: 2025/02/26 07:57:40 by bde-wits         ###   ########.fr       */
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
		AForm(const std::string named, int grad, int grad_ex);// polymorphisme
		AForm(AForm &cpy); // return copie du contenue
		virtual	~AForm();
		void			beSigned(Bureaucrat& agent); 
		//passe la fonction en heritage et abstraite force de la reimplemente dans les class dérive
		virtual void	execute(Bureaucrat const &agen) const = 0;
		int	getGrade() const;
		bool			getSigne() const;
		std::string		getName() const;
		int	getGrade_exec() const;
		AForm &operator=(AForm const &cpy);
	private:
		std::string 	name;//name of the AForm
		bool			signe;//are AForm signed ?
		const int	grade;//lvl required sign
		const int	grade_exec;//lvl required for execute the AForm
};

std::ostream&	operator<<(std::ostream& out, AForm& f);

// void	AForm::execute(Bureaucrat const &agent) const
// {
// 	if (this->getSigne() != true)
// 		throw (NotSignedAForm());
// 	if (this->getGrade() > this->getGrade_exec())
// 		throw (GradeTooLowException());
// 	std::cout << "Informs that " << this->name << " AForm has been execute." << std::endl;
// }

// #endif