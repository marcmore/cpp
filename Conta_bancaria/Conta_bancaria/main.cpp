#include <iostream>
#include <string>
#include "Conta.hpp"
#include "Titular.hpp"
#include "Cpf.hpp"

using namespace std;

void ExibeSaldo(Conta& conta) {
  
  cout<<"O saldo da conta é:"<< conta.recuperaSaldo()<<endl;
}


int main() {

  Titular titular_umaConta("Marcelo", Cpf("123.456.789"));
  Conta umaConta("123456", titular_umaConta);

  umaConta.depositar(500);
  umaConta.sacar(200);
  ExibeSaldo(umaConta);

  Titular titular_umaOutraConta("Antonio", Cpf("12345"));

  Conta umaOutraConta("123", titular_umaOutraConta);
  umaOutraConta.depositar(300);
  umaOutraConta.sacar(200);
  ExibeSaldo(umaOutraConta);

  cout<< "O número de contas é: " << Conta::recuperaNumeroContas() << endl;

  cout<< "Titular de uma Conta é: " << titular_umaConta.recuperaNome() << endl;

  cout << "Titular de uma Conta é: " << titular_umaOutraConta.recuperaNome() << endl;

  //cout << "CPF de uma Conta é: " << titular_umaOutraConta.recuperaNome() << endl;


  return 0;
}

