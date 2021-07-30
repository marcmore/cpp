#include "Gerente.hpp"

Gerente::Gerente(std::string nome, Cpf cpf, float salario, std::string senha)
	:Funcionario(nome, cpf, salario), Autenticavel(senha)
{

}

float Gerente::bonificacao() const
{
	return recuperaSalario() * 0.5;
}