/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-wits <bde-wits@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:09:34 by bde-wits          #+#    #+#             */
/*   Updated: 2025/03/03 13:42:16 by bde-wits         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ShrubberyCreationForm: Required grades: sign 145, exec 137
// Create a file <target>_shrubbery in the working directory, and writes ASCII trees
// inside it.

#pragma once
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"

class OpenFileException : public std::exception
{
	public:
		const char* what() const throw()
		{
			return "ShrubberyCreationForm was unable to open the file! (check permissions)";
		}
};

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm &cpy);
		~ShrubberyCreationForm();
		ShrubberyCreationForm	&operator=(const ShrubberyCreationForm cpy);
		void execute(Bureaucrat const &agent) const;
	private:
		std::string	target;
};
