/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-wits <bde-wits@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:08:14 by bde-wits          #+#    #+#             */
/*   Updated: 2025/02/25 09:52:46 by bde-wits         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

// int main()
// {
// 	try {
// 		Bureaucrat boss(1); // Grade 1, donc il peut tout faire
// 		PresidentialPardonForm form("Alice");

// 		std::cout << form << std::endl;

// 		boss.executeForm(form); // Erreur : le formulaire n'est pas signé

// 		form.beSigned(boss); // Boss signe le formulaire
// 		boss.executeForm(form); // Maintenant, il peut l'exécuter !

// 	} catch (const std::exception &e) {
// 		std::cerr << "Exception: " << e.what() << std::endl;
// 	}
// 	return 0;
// }

int main()
{
	try
	{
		// Création d'un bureaucrate avec un grade suffisant
		Bureaucrat bob(40);
		std::cout << bob << std::endl;

		// Création du formulaire
		RobotomyRequestForm form("Céliant");
		std::cout << "Form created: " << form.getName() << std::endl;

		// Signature du formulaire
		bob.signForm(form);
		
		// Exécution du formulaire
		bob.executeForm(form);
	}
	catch (std::exception &e)
	{
		std::cerr << "Erreur : " << e.what() << std::endl;
	}
	return 0;
}
