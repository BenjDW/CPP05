/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-wits <bde-wits@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 08:32:11 by bde-wits          #+#    #+#             */
/*   Updated: 2025/02/11 08:37:21 by bde-wits         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <ostream>

int main()
{
	try 
	{
		// Bureaucrat avec grade invalide (trop bas)
		Bureaucrat lowGrade(151); // Va lancer une exception
	} 
	catch (const std::exception &e)
	{
		std::cerr << "Erreur : " << e.what() << std::endl;
	}

	try 
	{
		// Bureaucrat avec grade invalide (trop haut)
		Bureaucrat highGrade(0); // Va lancer une exception
	} 
	catch (const std::exception &e)
	{
		std::cerr << "Erreur : " << e.what() << std::endl;
	}

	try
	{
		// Bureaucrat et Form valides
		Bureaucrat b(11); // Grade maximum
		Form taxForm;

		std::cout << b << std::endl;
		std::cout << taxForm << std::endl;

		// Tentative de signer le formulaire
		b.signForm(taxForm);

		// Vérifier que le formulaire est signé
		std::cout << "Form status: " << (taxForm.getSigne() ? "Signed" : "Not signed") << std::endl;
		std::cout << taxForm.getSigne() << std::endl;
		b.signForm(taxForm);
		// Incrémenter le grade (va échouer, car déjà au maximum)
		b.decremental_grade();
		b.signForm(taxForm);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Erreur : " << e.what() << std::endl;
	}
	return 0;
}
