#include "Pessoa.hpp"
#include <iostream>

Pessoa::Pessoa(std::string nome, Cpf cpf)
  :nome(nome), cpf(cpf)
{
  verificaTamanhoDoNome();
}

void Pessoa::verificaTamanhoDoNome()
{
  if (nome.size() < 5)
  {
    std::cout << "Nome muito curto" << std::endl;
    exit(1);
  }
}