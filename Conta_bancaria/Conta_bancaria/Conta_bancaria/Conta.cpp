#include "Conta.hpp"
#include <iostream>

int Conta::numero_contas = 0;

//Conta::Conta(std::string numero, std::string nomeTitular, std::string cpfTitular) {
//
//  this->numero = numero;
//  this->nomeTitular = nomeTitular;
//  this->cpfTitular = cpfTitular;
//  this->saldo = 0;
//}

Conta::Conta(std::string numero, Titular titular) 
  :numero(numero), titular(titular),saldo(0)
{
  numero_contas++;
}

Conta::~Conta()
{
  numero_contas--;
  std::cout << "Destrutor da conta" << std::endl;
}

int Conta::recuperaNumeroContas()
{
  return numero_contas;
}


void Conta::sacar(float valorASacar) {


	float tarifaDeSaque = valorASacar * taxaDeSaque();
	float valorDoSaque = valorASacar + tarifaDeSaque;

	if (valorASacar < 0) {
		std::cout << "Não pode sacar valor negativo" << std::endl;
		return;
	}

	if (valorDoSaque > saldo) {
		std::cout << "Saldo insuficiente" << std::endl;
		return;
	}

	saldo -= valorDoSaque;
}

void Conta::depositar(float valorADepositar) {
  if (valorADepositar < 0) {
    std::cout << "Não pode depositar valor negativo" << std::endl;
    return;
  }
  saldo += valorADepositar;
 
}

float Conta::recuperaSaldo() {
  return saldo;
}