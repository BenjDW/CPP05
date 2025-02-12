/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-wits <bde-wits@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:10:10 by bde-wits          #+#    #+#             */
/*   Updated: 2025/02/12 05:19:11 by bde-wits         ###   ########.fr       */
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
		~RobotomyRequestForm();
	private:
		std::string	target;
};

RobotomyRequestForm::RobotomyRequestForm(/* args */)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}
