/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-wits <bde-wits@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:54:54 by bde-wits          #+#    #+#             */
/*   Updated: 2025/02/11 07:38:13 by bde-wits         ###   ########.fr       */
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

// Conseils pour réussir
// Travaille par étapes :

// Commence par coder la classe Form avec ses attributs, constructeurs, et getters.
// Implémente les exceptions.
// Ajoute la méthode beSigned() pour valider la signature.
// Enfin, mets à jour la classe Bureaucrat pour inclure l'interaction.
// Teste chaque partie individuellement :

// Vérifie que les exceptions se lèvent correctement.
// Teste la signature d'un formulaire par un bureaucrate.

// Then, let’s make a Form class. It has:
// • A constant name.
// • A boolean indicating whether it is signed (at construction, it’s not).
// • A constant grade required to sign it.
// • And a constant grade required to execute it.
// All these attributes are private, not protected

// Add also a beSigned() member function to the Form that takes a Bureaucrat as
// parameter. It changes the form status to signed if the bureaucrat’s grade is high enough
// (higher or egal to the required one).


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
// {
// 	out << f.getName() << " Form , Form grade " << f.getGrade() << ", Form grade execution" << "" << std::endl;
// 	return (out);
// }

// void	Form::beSigned(Bureaucrat& agent)
// {
// 	if (agent.getGrade() < 1)
// 		throw(GradeTooHighException());
// 	else if (agent.getGrade() > 150 || agent.getGrade() > this->grade)
// 		throw(GradeTooLowException());
// 	else if (this->signe == false)
// 		this->signe = true;
// 	else
// 		throw(AlreadySignedException());
// }

// bool	Form::getSigne()
// {
// 	return (this->signe);
// }

// std::string	Form::getName()
// {
// 	return (this->name);
// }

// const int32_t	Form::getGrade_exec()
// {
// 	return (this->grade_exec);
// }

// const int32_t	Form::getGrade()
// {
// 	return (this->grade);
// }

// Form::Form() : name ("Triple The Tax"), signe (false), grade (11), grade_exec (12)
// {
// }

// Form::Form(const std::string named) : signe (false), grade (11), grade_exec (12)
// {
// 	this->name = named;
// }

// Form::Form(Form &cpy) : signe (cpy.signe), grade(cpy.grade), grade_exec (cpy.grade_exec), name (cpy.name)
// {
// 	// this->name = cpy.name;
// }

// Form::~Form()
// {
// }

// #endif