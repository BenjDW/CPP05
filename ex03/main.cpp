/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-wits <bde-wits@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:08:14 by bde-wits          #+#    #+#             */
/*   Updated: 2025/03/03 13:29:22 by bde-wits         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
    Intern intern;

    AForm* form1 = intern.makeForm("shrubbery creation", "Garden");
    AForm* form2 = intern.makeForm("robotomy request", "Patient");
    AForm* form3 = intern.makeForm("presidential pardon", "Prisoner");
    AForm* form4 = intern.makeForm("unknown form", "Nobody");

    if (form1)
        delete(form1);
    if (form2)
        delete(form2);
    if (form3)
	{
        delete(form3);
	}
	if (form4 != NULL)
		delete(form4);

    return (0);
}