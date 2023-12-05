/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioda-si <dioda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 00:35:16 by dioda-si          #+#    #+#             */
/*   Updated: 2023/12/05 00:35:18 by dioda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# ifndef SHRUBBERY_TREE
# define SHRUBBERY_TREE \
"          &&& &&  & &&\n" \
"      && &\\/&\\|& ()|/ @, &&\n" \
"      &\\/(/&/&||/& /_/)_&/_&\n" \
"   &() &\\/&|()|/&\\/ '%\" & ()\n" \
"  &_\\_&&_\\ |& |&&/&__%_/_& &&\n" \
"&&   && & &| &| /& & % ()& /&&\n" \
" ()&_---()&\\&\\|&&-&&--%---()~\n" \
"     &&     \\|||\n" \
"             |||\n" \
"             |||\n" \
"             |||\n" \
"       , -=-~  .-^- _\n"
#endif

# include "AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm {
	private:
		std::string	_target;

	public:
		// Orthodox Canonical Form        
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &copy);
		virtual ~ShrubberyCreationForm(void); //são parte da prática de programação defensiva e do uso de polimorfismo.
		// Permite a liberação adequada de recursos quando um objeto derivado é deletado através de um ponteiro para a classe base.

		// Others Constructors: Todos eles levam apenas um parâmetro em seu construtor: o alvo do formulário.
		ShrubberyCreationForm(const std::string &target);

		// Implementação da função execute para ShrubberyCreationForm
		virtual void execute(const Bureaucrat &executor) const; //Permite que as classes derivadas forneçam suas próprias implementações da função execute.
};

std::ostream	&operator<<(std::ostream &str, ShrubberyCreationForm const &form);

#endif
