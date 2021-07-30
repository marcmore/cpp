#include "ContaCorrente.hpp"
#include <iostream>

ContaCorrente::ContaCorrente(std::string numero, Titular titular)
	:Conta(numero, titular)
{

}

ContaCorrente::~ContaCorrente()
{

	std::cout << "Destrutor da conta corrente" << std::endl;
}

float ContaCorrente::taxaDeSaque() const {

	return 0.05;
}

void ContaCorrente::transferir(Conta& destino, float valor)
{
	destino.depositar(valor);
	sacar(valor);
}