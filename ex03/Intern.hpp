/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-wits <bde-wits@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 08:00:58 by bde-wits          #+#    #+#             */
/*   Updated: 2025/03/03 13:28:49 by bde-wits         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// cannonical form
// Constructeur par défaut
// • Constructeur de recopie
// • Opérateur d’affectation
// • Destructeur

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