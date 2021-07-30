#pragma once
#include "Conta.hpp"

class ContaCorrente: public Conta {

public:
	ContaCorrente(std::string  numero, Titular titular);
	~ContaCorrente();
	float taxaDeSaque() const override;
	void transferir(Conta& destino, float valor);
};
