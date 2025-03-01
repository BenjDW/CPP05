/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-wits <bde-wits@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 08:00:58 by bde-wits          #+#    #+#             */
/*   Updated: 2025/03/01 09:14:04 by bde-wits         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// cannonical form
// Constructeur par défaut
// • Constructeur de recopie
// • Opérateur d’affectation
// • Destructeur


// However, the intern has one important capacity: the makeForm() function. It takes
// two strings. 
// The first one is the name of a form and the second one is the target of the
// form. It return a pointer to a Form object (whose name is the one passed as parameter)
// whose target will be initialized to the second parameter.

// It will print something like:
// Intern creates <form>
// If the form name passed as parameter doesn’t exist, print an explicit error message.
#pragma once
#include "AForm.hpp"

class Intern
{
	public:
		Intern();
		~Intern();
		AForm* makeForm(std::string name, std::string target);
		std::string function[3];
	private:
		AForm* createShrubbery(std::string target);
		AForm* createRobotomy(std::string target);
		AForm* createPresidential(std::string target);
};