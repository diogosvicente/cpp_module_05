#include "Utils.hpp"

void customPrint(const std::string& text, const std::string& color)
{
	std::cout << color << text << RESET << std::endl;
}

void brCustomPrint(const std::string& text, const std::string& color)
{
	std::cout << std::endl << color << text << RESET << std::endl;
}

// Função para gerar um número aleatório entre 1 e 100
int getRandomNumber()
{
    static bool seedInitialized = false;

    if (!seedInitialized) {
        srand(static_cast<unsigned int>(time(NULL)));
        seedInitialized = true;
    }

    return rand() % 100 + 1;
}


// Função para verificar se um número é ímpar (retorna 1 para ímpar e 0 para par)
int isOdd(int number)
{
    return number % 2;
}

// Função única que engloba a inicialização do seed, geração de números aleatórios e verificação de paridade
int generateRandomEvenOrOdd()
{
    int randomNumber = getRandomNumber();
    return isOdd(randomNumber);
}