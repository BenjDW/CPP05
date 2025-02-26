/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-wits <bde-wits@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 01:54:54 by bde-wits          #+#    #+#             */
/*   Updated: 2025/02/26 07:57:11 by bde-wits         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

void	ShrubberyCreationForm::execute(Bureaucrat const &agent) const
{
	if (this->getSigne() != true)
		throw (NotSignedForm()); 
	if (agent.getGrade() > this->getGrade_exec())
		throw (GradeTooLowException());
	std::ofstream of;
	of.open((this->target + "_shrubbery").c_str());
	if (of.good() == false)
		throw OpenFileException();
	of << "⠀⢤⣤⣤⣤⣤⣤⠠⣤⣤⡄⢠⣤⣤⡀⢠⣤⣤⣤⣤⠄⢠⣤⣤⣤⣤⣤⣤⡤⠀" << std::endl;
	of << "⠀⠈⢻⣿⡿⠛⠛⠀⠈⠋⣠⣾⣿⣿⣷⣄⠙⠛⠋⣡⡄⠸⣿⣿⣿⡿⠛⠛⠁⠀" << std::endl;
	of << "⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	of << "⠀⠀⠀⠀⠀⠀⠀⠀⢹⣿⣿⠿⠻⣿⣿⣿⠟⠿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	of << "⠀⠀⠀⠀⠀⠀⠀⠀⠘⢋⣠⡶⠄⠙⡿⠃⠰⢦⣄⡙⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	of << "⠀⠀⠀⠀⠀⠀⠀⠀⠴⠋⠁⠀⠀⢸⣿⣇⠀⠀⠈⠛⠶⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	of << "⠀⠀⠀⠀⠀⠀⠀⠀⢠⣤⣴⣶⠀⣾⣿⣿⠀⢶⣦⣤⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	of << "⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣟⠁⢴⣿⣿⣿⡶⠄⠙⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	of << "⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⠿⠓⠀⣈⢉⡁⠀⠲⠿⢿⣿⡄⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	of << "⠀⠀⠀⠀⠀⠀⠀⠀⠠⠤⠶⠾⠿⠟⠛⠻⠿⠶⠶⠤⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	of << "⠀⠀⠀⠀⠀⠀⠀⢠⣶⣶⣶⡶⠀⠀⠀⠀⠀⣶⣶⣶⣶⣾⣆⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	of << "⠀⠀⠀⠀⠀⠀⣴⣿⣿⣿⣿⠃⠀⠀⠀⠀⠀⢸⣿⣿⣿⣿⣿⣦⡀⠀⠀⠀⠀⠀" << std::endl;
	of << "⠀⠀⠀⢀⣴⣾⣿⣿⣿⣿⣿⡄⠀⠀⠀⠀⠀⢸⣿⣿⣿⡿⣿⣿⣿⣦⡀⠀⠀⠀" << std::endl;
	of << "⠀⠐⠚⠛⠛⠉⠁⠸⣿⣿⣿⠃⠀⠀⠀⠀⠀⠈⠻⣿⡏⠀⠀⠉⠙⠻⠿⣦⡀⠀" << std::endl;
	of << "⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	of << "⠀⢤⣤⣤⣤⣤⣤⠠⣤⣤⡄⢠⣤⣤⡀⢠⣤⣤⣤⣤⠄⢠⣤⣤⣤⣤⣤⣤⡤⠀" << std::endl;
	of << "⠀⠈⢻⣿⡿⠛⠛⠀⠈⠋⣠⣾⣿⣿⣷⣄⠙⠛⠋⣡⡄⠸⣿⣿⣿⡿⠛⠛⠁⠀" << std::endl;
	of << "⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	of << "⠀⠀⠀⠀⠀⠀⠀⠀⢹⣿⣿⠿⠻⣿⣿⣿⠟⠿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	of << "⠀⠀⠀⠀⠀⠀⠀⠀⠘⢋⣠⡶⠄⠙⡿⠃⠰⢦⣄⡙⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	of << "⠀⠀⠀⠀⠀⠀⠀⠀⠴⠋⠁⠀⠀⢸⣿⣇⠀⠀⠈⠛⠶⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	of << "⠀⠀⠀⠀⠀⠀⠀⠀⢠⣤⣴⣶⠀⣾⣿⣿⠀⢶⣦⣤⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	of << "⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣟⠁⢴⣿⣿⣿⡶⠄⠙⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	of << "⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⠿⠓⠀⣈⢉⡁⠀⠲⠿⢿⣿⡄⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	of << "⠀⠀⠀⠀⠀⠀⠀⠀⠠⠤⠶⠾⠿⠟⠛⠻⠿⠶⠶⠤⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	of << "⠀⠀⠀⠀⠀⠀⠀⢠⣶⣶⣶⡶⠀⠀⠀⠀⠀⣶⣶⣶⣶⣾⣆⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	of << "⠀⠀⠀⠀⠀⠀⣴⣿⣿⣿⣿⠃⠀⠀⠀⠀⠀⢸⣿⣿⣿⣿⣿⣦⡀⠀⠀⠀⠀⠀" << std::endl;
	of << "⠀⠀⠀⢀⣴⣾⣿⣿⣿⣿⣿⡄⠀⠀⠀⠀⠀⢸⣿⣿⣿⡿⣿⣿⣿⣦⡀⠀⠀⠀" << std::endl;
	of << "⠀⠐⠚⠛⠛⠉⠁⠸⣿⣿⣿⠃⠀⠀⠀⠀⠀⠈⠻⣿⡏⠀⠀⠉⠙⠻⠿⣦⡀⠀" << std::endl;
	of << "⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	of.close();
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm cpy)
{
	this->target = cpy.target;
	return *this;
}

ShrubberyCreationForm::ShrubberyCreationForm() : AForm ("ShrubberyCreationForm", 145, 137), target ("Céliant")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm ("ShrubberyCreationForm", 72, 45), target (target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &cpy) : AForm (cpy.getName(), cpy.getGrade(), cpy.getGrade_exec()), target (cpy.target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}