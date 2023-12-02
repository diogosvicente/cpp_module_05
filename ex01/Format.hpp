/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Format.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioda-si <dioda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:59:17 by dioda-si          #+#    #+#             */
/*   Updated: 2023/12/02 15:59:20 by dioda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMAT_HPP
# define FORMAT_HPP

#include <iostream>

void customPrint(const std::string& text, const std::string& color);
void brCustomPrint(const std::string& text, const std::string& color);

//FORMAT
# define RED	"\033[31m"
# define GREEN	"\033[32m"
# define YELLOW	"\033[33m"

//FORMAT
# define ULINE	"\033[4m"
# define BOLD	"\033[1m"
# define ITALIC	"\033[3m"

//RESET
# define RESET	"\033[0m"



#endif
