/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-wits <bde-wits@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:08:14 by bde-wits          #+#    #+#             */
/*   Updated: 2025/02/24 02:00:08 by bde-wits         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try {
		Bureaucrat boss(1); // Grade 1, donc il peut tout faire
		PresidentialPardonForm form("Alice");

		std::cout << form << std::endl;

		boss.executeForm(form); // Erreur : le formulaire n'est pas signé

		form.beSigned(boss); // Boss signe le formulaire
		boss.executeForm(form); // Maintenant, il peut l'exécuter !

	} catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	return 0;
}
