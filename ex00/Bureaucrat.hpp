/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioda-si <dioda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 22:36:42 by dioda-si          #+#    #+#             */
/*   Updated: 2023/10/28 22:36:59 by dioda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
# include "Format.hpp"

/**
 *	Orthodox Canonical Form Class
 *	1. A Bureaucrat constructor that initializes a Bureaucrat.
 *	2. A copy constructor.
 *	3. A copy assignment operator overload.
 *	4. A destructor.
 *
 */

class Bureaucrat
{
	private:
		std::string	const _name;
		int _grade;
		static const int _highestGrade = 1;
    	static const int _lowestGrade = 150;

	public:
		/* 1 */ Bureaucrat(void);
		/* 2 */ Bureaucrat(Bureaucrat const &copy);
		/* 3 */ Bureaucrat const &operator=(Bureaucrat const &copy);
		/* 4 */ ~Bureaucrat(void);

		/* 5 */ Bureaucrat(std::string const &name, int grade);

		std::string const &getName(void) const;
		int 		const &getGrade(void) const;

		void incrementGrade(void);
	    void decrementGrade(void);

		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif