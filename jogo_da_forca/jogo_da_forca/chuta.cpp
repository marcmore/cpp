#include <iostream>
#include "letra_existe.hpp"
#include <vector>
#include <map>
#include "chuta.hpp"

//extern std::map<char, bool> chutou;
//extern std::vector<char> chutes_errados;

void chuta(std::map<char, bool>& chutou, std::vector<char>& chutes_errados,std::string& palavra_secreta) {
	std::cout << "Seu chute: ";
	char chute;
	std::cin >> chute;

	chutou[chute] = true;

	if (letra_existe(chute,palavra_secreta)) {
		std::cout << "Voc� acertou! Seu chute est� na palavra." << std::endl;
	}
	else {
		std::cout << "Voc� errou! Seu chute n�o est� na palavra." << std::endl;
		chutes_errados.push_back(chute);
	}
	std::cout << std::endl;
}