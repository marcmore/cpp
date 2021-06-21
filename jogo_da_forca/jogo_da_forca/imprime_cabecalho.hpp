#pragma once // usa - se pragma once para em cabe�alho para avisar que esse arquivo seja incluido apenas uma vez durante a compila��o

#include <iostream>

inline void imprime_cabecalho() { // usa se inline no cabe�alho para que o processador n�o precise alocar outra lugar na mem�ria para sua execu��o, ele j� pode executar no mesmo lugar onde � chamado a fun��o
	std::cout << "*********************" << std::endl;
	std::cout << "*** Jogo da Forca ***" << std::endl;
	std::cout << "*********************" << std::endl;
	std::cout << std::endl;
}
