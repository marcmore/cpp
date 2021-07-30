#pragma once
#include "Pessoa.hpp"
#include <string>
#include "Cpf.hpp"

class Funcionario:public Pessoa {

  private:
    float salario;

  public:
    Funcionario(std::string nome, Cpf cpf, float salario);
	std::string recuperaNome();
	virtual float bonificacao() const = 0;
	float recuperaSalario() const;
    

};
