/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Default.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioda-si <dioda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 22:36:42 by dioda-si          #+#    #+#             */
/*   Updated: 2023/10/28 22:36:59 by dioda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFAULT_HPP
# define DEFAULT_HPP

/**
 *	Orthodox Canonical Form Class
 *	1. A default constructor that initializes a Default.
 *	2. A copy constructor.
 *	3. A copy assignment operator overload.
 *	4. A destructor.
 */

class Default
{
	private:
		std::string _name;

	public:
		/* 1 */ Default(void);
		/* 2 */ Default(Default const &copy);
		/* 3 */ Default const	&operator=(Default const &copy);
		/* 4 */ ~Default(void);
};

#endif