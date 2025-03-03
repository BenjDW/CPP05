/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-wits <bde-wits@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:08:14 by bde-wits          #+#    #+#             */
/*   Updated: 2025/03/03 13:23:49 by bde-wits         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
    try {
        Bureaucrat bob(40);
        ShrubberyCreationForm form("garden");

        std::cout << "--- Avant signature ---" << std::endl;
        bob.executeForm(form);
        
        std::cout << "--- Signature du formulaire ---" << std::endl;
        bob.signForm(form);
        
        std::cout << "--- Après signature, tentative d'exécution ---" << std::endl;
        bob.executeForm(form);
        
    } catch (const std::exception &e) 
	{
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}