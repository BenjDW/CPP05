/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-wits <bde-wits@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 08:01:01 by bde-wits          #+#    #+#             */
/*   Updated: 2025/03/03 13:28:15 by bde-wits         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// However, the intern has one important capacity: the makeForm() function. It takes
// two strings. 
// The first one is the name of a form and the second one is the target of the
// form. It return a pointer to a Form object (whose name is the one passed as parameter)
// whose target will be initialized to the second parameter.

// It will print something like:
// Intern creates <form>
// If the form name passed as parameter doesn’t exist, print an explicit error message.

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

AForm* Intern::createShrubbery(std::string target)
{
    return (new ShrubberyCreationForm(target));
}

AForm* Intern::createRobotomy(std::string target)
{
    return (new RobotomyRequestForm(target));
}

AForm* Intern::createPresidential(std::string target)
{
    return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(std::string name, std::string target) 
{
    std::string formNames[] = {"shrubbery creation", "robotomy request", "presidential pardon"};

    AForm* (Intern::*formCreators[])(std::string) = {
        &Intern::createShrubbery,
        &Intern::createRobotomy,
        &Intern::createPresidential
    };

    for (int i = 0; i < 3; i++)
    {
        if (name == formNames[i])
        {
            std::cout << "Intern creates " << name << std::endl;
            return (this->*formCreators[i])(target);
        }
    }
    
    std::cout << "Error: Form name '" << name << "' not found!" << std::endl;
    return NULL;
}

Intern::Intern()
{
}

Intern::~Intern()
{
}
