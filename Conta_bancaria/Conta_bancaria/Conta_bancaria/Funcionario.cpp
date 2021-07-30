#include "Funcionario.hpp"

Funcionario::Funcionario(std::string nome, Cpf cpf, float salario)
  :Pessoa(nome, cpf), salario(salario)
{

}

std::string Funcionario::recuperaNome()
{
	return nome;
}

float Funcionario::recuperaSalario() const
{
	return salario;
}