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
