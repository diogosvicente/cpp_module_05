/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioda-si <dioda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 00:35:05 by dioda-si          #+#    #+#             */
/*   Updated: 2023/12/05 00:35:07 by dioda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm {
private:
	std::string _target;

public:
	// Orthodox Canonical Form Class
	PresidentialPardonForm(void);
	PresidentialPardonForm(const PresidentialPardonForm &copy);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &copy);
	virtual ~PresidentialPardonForm(void);

	// Main Constructor from subject
	PresidentialPardonForm(const std::string &target);

	// Methods required from subject
	virtual void execute(const Bureaucrat &executor) const;

	// Operator overload
	friend std::ostream &operator<<(std::ostream &os, const PresidentialPardonForm &aform);
};

#endif
