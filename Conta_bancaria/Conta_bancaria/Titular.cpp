#include <iostream>
#include "Titular.hpp"

Titular::Titular(std::string nome, Cpf cpf)
  :nome(nome), cpf(cpf)
{
  verificaTamanhoDoNome();
}

void Titular::verificaTamanhoDoNome()
{
  if (nome.size() < 5)
  {
    std::cout<<"Nome muito curto"<<std::endl;
    exit(1);
  }
}

std::string Titular::recuperaNome()
{
  return nome;
}