#pragma once
#include <string>
#include "Titular.hpp"

class Conta {

private:
  static int numero_contas;

public:
  static int recuperaNumeroContas();

private:
  std::string numero;
  Titular titular;
  float saldo;

public: 
  ~Conta();
  Conta(std::string numero, Titular titular);
  void sacar (float valorASacar);
  void depositar (float valorADepositar);
  float recuperaSaldo();

};