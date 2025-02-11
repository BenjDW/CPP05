/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-wits <bde-wits@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 08:32:11 by bde-wits          #+#    #+#             */
/*   Updated: 2025/02/11 05:58:50 by bde-wits         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	try 
	{
        Bureaucrat	b(151); // Trop bas
    } 
	catch (const std::exception &e)
	{
        std::cerr << "Erreur : " << e.what() << std::endl;
    }

    try 
	{
        Bureaucrat b(0); // Trop haut
    }
	catch (const std::exception &e)
	{
        std::cerr << "Erreur : " << e.what() << std::endl;
    }

    try
	{
        Bureaucrat b(1);
		std::cout << b;
        b.incremental_grade(); // Trop haut après incrément
    } 
	catch (const std::exception &e)
	{
        std::cerr << "Erreur : " << e.what() << std::endl;
    }

    return 0;
}