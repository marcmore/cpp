#pragma once
# include <string>
#include "Titular.hpp"
#include "Conta.hpp"

class ContaPoupanca: public Conta {

public:
	ContaPoupanca(std::string  numero, Titular titular);
	~ContaPoupanca();
	float taxaDeSaque() const override;
};
