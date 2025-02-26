/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-wits <bde-wits@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 01:54:26 by bde-wits          #+#    #+#             */
/*   Updated: 2025/02/26 02:45:13 by bde-wits         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "cstdlib"

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm cpy)
{
	this->target = cpy.target;
	return *this;
}

void	RobotomyRequestForm::execute(Bureaucrat const &agent) const
{
	if (this->getSigne() != true)
		throw (NotSignedForm()); 
	if (agent.getGrade() > this->getGrade_exec())
		throw (GradeTooLowException());	
	std::cout << "BZZZZZZZT... *drilling noises* 🔩⚙️" << std::endl;
	if (std::rand() % 2) // Génère un nombre pseudo-aléatoire
		std::cout << "Informs that " << this->target << " has been robotomized in to a random human" << std::endl;
	else
		std::cout << "Informs that robotomy failed... oups céliant is still céliant" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm() : Form ("RobotomyRequestForm", 72, 45), target ("Céliant")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form ("RobotomyRequestForm", 72, 45), target (target)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &cpy) : Form (cpy.getName(), cpy.getGrade(), cpy.getGrade_exec()), target (cpy.target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}