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

protected:
  float saldo;

public: 
  virtual ~Conta();
  Conta(std::string numero, Titular titular);
  void sacar (float valorASacar);
  void depositar (float valorADepositar);
  float recuperaSaldo();
  virtual float taxaDeSaque() const = 0;

};