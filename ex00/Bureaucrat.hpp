/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-wits <bde-wits@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 08:32:09 by bde-wits          #+#    #+#             */
/*   Updated: 2025/02/11 07:40:22 by bde-wits         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <ostream>
#include <iomanip>
#include <string>
#include <exception>

// First, start by the smallest cog in this vast bureaucratic machine: the Bureaucrat.
// A Bureaucrat must have:
// • A constant name.
// • And a grade that ranges from 1 (highest possible grade) to 150 (lowest possible
// grade).
// Any attempt to instantiate a Bureaucrat using an invalid grade must throw an exception:
// either a Bureaucrat::GradeTooHighException or a Bureaucrat::GradeTooLowException

// To catch exceptions, a portion of code is placed under exception inspection. 
// This is done by enclosing that portion of code in a try-block. When an exceptional circumstance arises within that block,
// an exception is thrown that transfers the control to the exception handler. 
// If no exception is thrown, the code continues normally and all handlers are ignored.
// An exception is thrown by using the throw keyword from inside the try block. 
// Exception handlers are declared with the keyword catch, which must be placed immediately after the try block:

// try
// {
// /* do some stuff with bureaucrats */
// }
// catch (std::exception & e)
// {
// /* handle exception */
// }

// struct ooops : std::exception {
// 	const char* what() const noexcept {return "Ooops!\n";}
//   };
  
//   int main () {
// 	try {
// 		throw ooops();
// 	} catch (std::exception& ex) {
// 		std::cout << ex.what();
// 	}
// 	return 0;
//   }

// utilise le constructeur et destructeur par defauts
// what = quel erreur , definit ensuite
class GradeTooHighException : public std::exception
{
	public:
		const char* what() const noexcept 
		{
			return "Grade Too High !";
		}
};

class GradeTooLowException : public std::exception
{
	public:
		const char* what() const noexcept 
		{
			return "Grade Too Low !";
		}
};

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(int lvl);
		Bureaucrat(Bureaucrat& cpy);
		~Bureaucrat();
		std::string	getName();
		std::int32_t getGrade();
		void	incremental_grade();
		void	decremental_grade();
		// std::exception GradeTooHighException(); mauvais implementation class neccessaire
		// std::exception GradeTooLowException();
		private:
		const std::string	name;
		std::int32_t 		Grade;
};
	
std::ostream& operator<<(std::ostream& out, Bureaucrat& b); //  insertion («) operator to print something like (without the angle brackets):
// std::exception Bureaucrat::GradeTooHighException()
// {
// 	if (this->Grade < 1)
// 		return (std::exception());
// }

// std::exception Bureaucrat::GradeTooLowException()
// {
// 	if (this->Grade > 150)
// 		return (std::exception());
// }

std::ostream&	operator<<(std::ostream& out, Bureaucrat& b)
{
	out << b.getName() << ", bureaucrat grade " << b.getGrade() << "." << std::endl;
	return (out);
}

void	Bureaucrat::incremental_grade()
{
	Grade -= 1;
	if (this->Grade < 1)
		throw (GradeTooHighException());
	// try
	// {
	// 	GradeTooHighException();
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
	
}

void	Bureaucrat::decremental_grade()
{
	Grade += 1;
	if (this->Grade > 150)
		throw (GradeTooLowException());
	// try
	// {
	// 	Bureaucrat::GradeTooLowException();
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
}

std::string	Bureaucrat::getName()
{
	return (this->name);
}

std::int32_t	Bureaucrat::getGrade()
{
	return (this->Grade);
}

Bureaucrat::Bureaucrat() : name ("bobby")
{
	// this->name = "Bobby";
	this->Grade = 10;
}

Bureaucrat::Bureaucrat(int lvl) : name ("ansar_tek")
{
	Grade = lvl;
	if (Grade < 1)
		throw (GradeTooHighException());
	if (Grade > 150)
		throw (GradeTooLowException());
	// try
	// {
	// 	bureaucrat::GradeTooHighException();
	// 	bureaucrat::GradeTooLowException();
	// }
}

// return a copie du contenue de l'objet envoyer
Bureaucrat::Bureaucrat(Bureaucrat &cpy)
{
	Grade = cpy.Grade;
}

Bureaucrat::~Bureaucrat()
{
}

#endif