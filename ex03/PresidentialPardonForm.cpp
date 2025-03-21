/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-wits <bde-wits@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 01:53:59 by bde-wits          #+#    #+#             */
/*   Updated: 2025/02/26 07:57:35 by bde-wits         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm cpy)
{
	this->target = cpy.target;
	return *this;
}

void	PresidentialPardonForm::execute(Bureaucrat const &agent) const
{
	if (this->getSigne() != true)
		throw (NotSignedForm());
	if (agent.getGrade() > this->getGrade_exec())
		throw (GradeTooLowException());
	std::cout << "Informs that " << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), target ("Céliant")
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), target (target)
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &cpy) : AForm(cpy.getName(), cpy.getGrade(), cpy.getGrade_exec()), target (cpy.target)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}
