/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-wits <bde-wits@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:10:27 by bde-wits          #+#    #+#             */
/*   Updated: 2025/02/12 05:14:21 by bde-wits         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// PresidentialPardonForm: Required grades: sign 25, exec 5
// Informs that <target> has been pardoned by Zaphod Beeblebrox.

#include "AForm.hpp"

class PresidentialPardonForm : public Form
{
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm &cpy);
		~PresidentialPardonForm();
		const	void execute(); //execute la version presidentialform
	private:
		std::string	target;
};

const void	PresidentialPardonForm::execute()
{
	if (this->getSigne() != true)
		throw (AlreadySignedException()); 
	if (this->getGrade() > this->getGrade_exec())
		throw (GradeTooLowException());
	std::cout << "Informs that " << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm() : Form ("PresidentialPardonForm", 25, 5), target ("Céliant")
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form ("PresidentialPardonForm", 25, 5), target (target)
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &cpy) : Form (cpy.getName(), cpy.getGrade(), cpy.getGrade_exec()), target (cpy.target)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}
