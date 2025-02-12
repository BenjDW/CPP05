/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-wits <bde-wits@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:09:34 by bde-wits          #+#    #+#             */
/*   Updated: 2025/02/12 01:55:25 by bde-wits         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ShrubberyCreationForm: Required grades: sign 145, exec 137
// Create a file <target>_shrubbery in the working directory, and writes ASCII trees
// inside it.

#include "AForm.hpp"

class ShrubberyCreationForm : public Form
{
	public:
		ShrubberyCreationForm();
		~ShrubberyCreationForm();
	private:
		std::string	target;
};

ShrubberyCreationForm::ShrubberyCreationForm()
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}
