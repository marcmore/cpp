#pragma once
#include "Cpf.hpp"



Cpf::Cpf(std::string numero)
  :numero(numero)
{
}

std::string Cpf::recuperaCpf()
{
  return numero;
}



