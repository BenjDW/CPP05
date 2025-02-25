/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-wits <bde-wits@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:10:27 by bde-wits          #+#    #+#             */
/*   Updated: 2025/02/25 10:48:16 by bde-wits         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
// PresidentialPardonForm: Required grades: sign 25, exec 5
// Informs that <target> has been pardoned by Zaphod Beeblebrox.

#include "AForm.hpp"

class NotSignedForm : public std::exception
{
	public:
		const char* what() const noexcept
		{
			return "The form is not signed!";
		}
};


class PresidentialPardonForm : public Form
{
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm &cpy);
		~PresidentialPardonForm();
		PresidentialPardonForm	&operator=(const PresidentialPardonForm cpy);
		void execute(Bureaucrat const &agen) const; //execute la version presidentialform
	private:
		std::string	target;
};

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm cpy)
{
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

PresidentialPardonForm::PresidentialPardonForm() : Form("PresidentialPardonForm", 25, 5), target ("Céliant")
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("PresidentialPardonForm", 25, 5), target (target)
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &cpy) : Form(cpy.getName(), cpy.getGrade(), cpy.getGrade_exec()), target (cpy.target)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}
