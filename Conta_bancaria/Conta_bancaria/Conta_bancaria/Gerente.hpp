#pragma once
#include "Funcionario.hpp"
#include "Autenticavel.hpp"

class Gerente final: public Funcionario, public Autenticavel
{

public:
	Gerente(std::string nome, Cpf cpf, float salario, std::string senha);
	float bonificacao() const;

};