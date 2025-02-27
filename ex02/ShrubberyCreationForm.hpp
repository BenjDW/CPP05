/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-wits <bde-wits@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:09:34 by bde-wits          #+#    #+#             */
/*   Updated: 2025/02/26 07:57:45 by bde-wits         ###   ########.fr       */
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

// void	ShrubberyCreationForm::execute(Bureaucrat const &agent) const
// {
// 	if (this->getSigne() != true)
// 		throw (NotSignedForm()); 
// 	if (agent.getGrade() > this->getGrade_exec())
// 		throw (GradeTooLowException());
// 	std::ofstream of;
// 	of.open((this->target + "_shrubbery").c_str());
// 	if (of.good() == false)
// 		throw OpenFileException();
// 	of << "⠀⢤⣤⣤⣤⣤⣤⠠⣤⣤⡄⢠⣤⣤⡀⢠⣤⣤⣤⣤⠄⢠⣤⣤⣤⣤⣤⣤⡤⠀" << std::endl;
// 	of << "⠀⠈⢻⣿⡿⠛⠛⠀⠈⠋⣠⣾⣿⣿⣷⣄⠙⠛⠋⣡⡄⠸⣿⣿⣿⡿⠛⠛⠁⠀" << std::endl;
// 	of << "⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
// 	of << "⠀⠀⠀⠀⠀⠀⠀⠀⢹⣿⣿⠿⠻⣿⣿⣿⠟⠿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
// 	of << "⠀⠀⠀⠀⠀⠀⠀⠀⠘⢋⣠⡶⠄⠙⡿⠃⠰⢦⣄⡙⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
// 	of << "⠀⠀⠀⠀⠀⠀⠀⠀⠴⠋⠁⠀⠀⢸⣿⣇⠀⠀⠈⠛⠶⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
// 	of << "⠀⠀⠀⠀⠀⠀⠀⠀⢠⣤⣴⣶⠀⣾⣿⣿⠀⢶⣦⣤⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
// 	of << "⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣟⠁⢴⣿⣿⣿⡶⠄⠙⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
// 	of << "⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⠿⠓⠀⣈⢉⡁⠀⠲⠿⢿⣿⡄⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
// 	of << "⠀⠀⠀⠀⠀⠀⠀⠀⠠⠤⠶⠾⠿⠟⠛⠻⠿⠶⠶⠤⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
// 	of << "⠀⠀⠀⠀⠀⠀⠀⢠⣶⣶⣶⡶⠀⠀⠀⠀⠀⣶⣶⣶⣶⣾⣆⠀⠀⠀⠀⠀⠀⠀" << std::endl;
// 	of << "⠀⠀⠀⠀⠀⠀⣴⣿⣿⣿⣿⠃⠀⠀⠀⠀⠀⢸⣿⣿⣿⣿⣿⣦⡀⠀⠀⠀⠀⠀" << std::endl;
// 	of << "⠀⠀⠀⢀⣴⣾⣿⣿⣿⣿⣿⡄⠀⠀⠀⠀⠀⢸⣿⣿⣿⡿⣿⣿⣿⣦⡀⠀⠀⠀" << std::endl;
// 	of << "⠀⠐⠚⠛⠛⠉⠁⠸⣿⣿⣿⠃⠀⠀⠀⠀⠀⠈⠻⣿⡏⠀⠀⠉⠙⠻⠿⣦⡀⠀" << std::endl;
// 	of << "⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
// 	of << "⠀⢤⣤⣤⣤⣤⣤⠠⣤⣤⡄⢠⣤⣤⡀⢠⣤⣤⣤⣤⠄⢠⣤⣤⣤⣤⣤⣤⡤⠀" << std::endl;
// 	of << "⠀⠈⢻⣿⡿⠛⠛⠀⠈⠋⣠⣾⣿⣿⣷⣄⠙⠛⠋⣡⡄⠸⣿⣿⣿⡿⠛⠛⠁⠀" << std::endl;
// 	of << "⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
// 	of << "⠀⠀⠀⠀⠀⠀⠀⠀⢹⣿⣿⠿⠻⣿⣿⣿⠟⠿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
// 	of << "⠀⠀⠀⠀⠀⠀⠀⠀⠘⢋⣠⡶⠄⠙⡿⠃⠰⢦⣄⡙⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
// 	of << "⠀⠀⠀⠀⠀⠀⠀⠀⠴⠋⠁⠀⠀⢸⣿⣇⠀⠀⠈⠛⠶⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
// 	of << "⠀⠀⠀⠀⠀⠀⠀⠀⢠⣤⣴⣶⠀⣾⣿⣿⠀⢶⣦⣤⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
// 	of << "⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣟⠁⢴⣿⣿⣿⡶⠄⠙⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
// 	of << "⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⠿⠓⠀⣈⢉⡁⠀⠲⠿⢿⣿⡄⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
// 	of << "⠀⠀⠀⠀⠀⠀⠀⠀⠠⠤⠶⠾⠿⠟⠛⠻⠿⠶⠶⠤⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
// 	of << "⠀⠀⠀⠀⠀⠀⠀⢠⣶⣶⣶⡶⠀⠀⠀⠀⠀⣶⣶⣶⣶⣾⣆⠀⠀⠀⠀⠀⠀⠀" << std::endl;
// 	of << "⠀⠀⠀⠀⠀⠀⣴⣿⣿⣿⣿⠃⠀⠀⠀⠀⠀⢸⣿⣿⣿⣿⣿⣦⡀⠀⠀⠀⠀⠀" << std::endl;
// 	of << "⠀⠀⠀⢀⣴⣾⣿⣿⣿⣿⣿⡄⠀⠀⠀⠀⠀⢸⣿⣿⣿⡿⣿⣿⣿⣦⡀⠀⠀⠀" << std::endl;
// 	of << "⠀⠐⠚⠛⠛⠉⠁⠸⣿⣿⣿⠃⠀⠀⠀⠀⠀⠈⠻⣿⡏⠀⠀⠉⠙⠻⠿⣦⡀⠀" << std::endl;
// 	of << "⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
// 	of.close();
// }

// ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm cpy)
// {
// 	return *this;
// }

// ShrubberyCreationForm::ShrubberyCreationForm() : AForm ("ShrubberyCreationForm", 145, 137), target ("Céliant")
// {
// }

// ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm ("ShrubberyCreationForm", 72, 45), target (target)
// {
// }

// ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &cpy) : AForm (cpy.getName(), cpy.getGrade(), cpy.getGrade_exec()), target (cpy.target)
// {
// }

// ShrubberyCreationForm::~ShrubberyCreationForm()
// {
// }


// const char *ShrubberyCreationForm::OpenFileException::what() const throw() 
// {
// 	return "ShrubberyCreationForm was unable to open the file! (check permissions)";
// }