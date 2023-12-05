/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioda-si <dioda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:04:28 by dioda-si          #+#    #+#             */
/*   Updated: 2023/12/05 11:04:30 by dioda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
	private:
		std::string _target;

	public:
		// Orthodox Canonical Form Class
		RobotomyRequestForm(void);
		RobotomyRequestForm(const RobotomyRequestForm &copy);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &copy);
		virtual ~RobotomyRequestForm(void);

		// Other Constructors - main from subject
		RobotomyRequestForm(const std::string &target);

		// Methods
		virtual void execute(const Bureaucrat &executor) const;
		static AForm *createRobotomyRequestForm(const std::string &target);
};

// Operator Overload
std::ostream &operator<<(std::ostream &os, const RobotomyRequestForm &aform);

#endif
