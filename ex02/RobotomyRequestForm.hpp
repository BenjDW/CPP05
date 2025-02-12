/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-wits <bde-wits@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:10:10 by bde-wits          #+#    #+#             */
/*   Updated: 2025/02/12 05:31:22 by bde-wits         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// RobotomyRequestForm: Required grades: sign 72, exec 45
// Makes some drilling noises. Then, informs that <target> has been robotomized
// successfully 50% of the time. Otherwise, informs that the robotomy failed.

#include "AForm.hpp"

class RobotomyRequestForm : public Form
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm &cpy);
		~RobotomyRequestForm();
		const void execute();
	private:
		std::string	target;
};

const void	RobotomyRequestForm::execute()
{
	if (this->getSigne() != true)
		throw (AlreadySignedException()); 
	if (this->getGrade() > this->getGrade_exec())
		throw (GradeTooLowException());
	std::cout << "Informs that " << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
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