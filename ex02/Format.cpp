#include "Format.hpp"

void customPrint(const std::string& text, const std::string& color)
{
	std::cout << color << text << RESET << std::endl;
}

void brCustomPrint(const std::string& text, const std::string& color)
{
	std::cout << std::endl << color << text << RESET << std::endl;
}
