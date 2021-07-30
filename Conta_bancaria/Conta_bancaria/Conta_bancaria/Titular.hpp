#pragma once
#include "Pessoa.hpp"
#include <string>
#include "Cpf.hpp"
#include "Autenticavel.hpp"

class Titular:public Pessoa, public Autenticavel
{
  public:
    Titular(std::string nome, Cpf cpf, std::string senha);
    std::string recuperaNome();
};
