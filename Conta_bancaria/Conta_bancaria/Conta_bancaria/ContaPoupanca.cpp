#include "ContaPoupanca.hpp"
#include <iostream>

ContaPoupanca::ContaPoupanca(std::string numero, Titular titular)
	:Conta(numero, titular)
{

}

ContaPoupanca::~ContaPoupanca()
{

	std::cout << "Destrutor da conta poupan�a" << std::endl;
}

float ContaPoupanca::taxaDeSaque() const {

	return 0.03;
}