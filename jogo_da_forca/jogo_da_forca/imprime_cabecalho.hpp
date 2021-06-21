#pragma once // usa - se pragma once para em cabeçalho para avisar que esse arquivo seja incluido apenas uma vez durante a compilação

#include <iostream>

inline void imprime_cabecalho() { // usa se inline no cabeçalho para que o processador não precise alocar outra lugar na memória para sua execução, ele já pode executar no mesmo lugar onde é chamado a função
	std::cout << "*********************" << std::endl;
	std::cout << "*** Jogo da Forca ***" << std::endl;
	std::cout << "*********************" << std::endl;
	std::cout << std::endl;
}
