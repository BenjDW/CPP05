/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-wits <bde-wits@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:10:10 by bde-wits          #+#    #+#             */
/*   Updated: 2025/03/03 13:41:27 by bde-wits         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// RobotomyRequestForm: Required grades: sign 72, exec 45
// Makes some drilling noises. Then, informs that <target> has been robotomized
// successfully 50% of the time. Otherwise, informs that the robotomy failed.
#pragma once
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm &cpy);
		~RobotomyRequestForm();
		RobotomyRequestForm	&operator=(const RobotomyRequestForm cpy);
		void execute(Bureaucrat const &agent) const;
	private:
		std::string	target;
};

// RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm cpy)
// {
// 	return *this;
// }

// void	RobotomyRequestForm::execute(Bureaucrat const &agent) const
// {
// 	std::srand(std::time(NULL)); // Initialise le générateur aléatoire
	
// 	if (this->getSigne() != true)
// 		throw (NotSignedForm()); 
// 	if (agent.getGrade() > this->getGrade_exec())
// 		throw (GradeTooLowException());	
// 	std::cout << "BZZZZZZZT... *drilling noises* 🔩⚙️" << std::endl;
// 	if (std::rand() % 2 == 0) // Génère un nombre pseudo-aléatoire
// 		std::cout << "Informs that " << this->target << " has been robotomized in to a random human" << std::endl;
// 	else
// 		std::cout << "Informs that robotomy failed... oups céliant is still céliant" << std::endl;
// }

// RobotomyRequestForm::RobotomyRequestForm() : AForm ("RobotomyRequestForm", 72, 45), target ("Céliant")
// {
// }

// RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm ("RobotomyRequestForm", 72, 45), target (target)
// {
// }

// RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &cpy) : AForm (cpy.getName(), cpy.getGrade(), cpy.getGrade_exec()), target (cpy.target)
// {
// }

// RobotomyRequestForm::~RobotomyRequestForm()
// {
// }