#include <iostream>
#include "Titular.hpp"

Titular::Titular(std::string nome, Cpf cpf, std::string senha)
  :Pessoa(nome,cpf), Autenticavel(senha)
{
  
}

std::string Titular::recuperaNome()
{
  return nome;
}