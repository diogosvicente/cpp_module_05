/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Format.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioda-si <dioda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:59:06 by dioda-si          #+#    #+#             */
/*   Updated: 2023/12/02 15:59:09 by dioda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Format.hpp"

void customPrint(const std::string& text, const std::string& color)
{
	std::cout << color << text << RESET << std::endl;
}

void brCustomPrint(const std::string& text, const std::string& color)
{
	std::cout << std::endl << color << text << RESET << std::endl;
}
