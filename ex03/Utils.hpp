/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioda-si <dioda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:04:37 by dioda-si          #+#    #+#             */
/*   Updated: 2023/12/05 11:04:39 by dioda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

#include <iostream>
#include <cstdlib> // Para rand
#include <ctime>   // Para time

void customPrint(const std::string& text, const std::string& color);
void brCustomPrint(const std::string& text, const std::string& color);
int getRandomNumber(void);
int isOdd(int number);
int generateRandomEvenOrOdd();

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
