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
	protected:

	public:
		/* 1 */ Bureaucrat(void);
		/* 2 */ Bureaucrat(Bureaucrat const &copy);
		/* 3 */ Bureaucrat const	&operator=(Bureaucrat const &copy);
		/* 4 */ ~Bureaucrat(void);
};