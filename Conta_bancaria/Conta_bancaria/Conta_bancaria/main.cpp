#include <iostream>
#include <string>
#include "Conta.hpp"
#include "ContaCorrente.hpp"
#include "Titular.hpp"
#include "Cpf.hpp"
#include "Funcionario.hpp"
#include "ContaPoupanca.hpp"
#include "Caixa.hpp"
#include "Autenticavel.hpp"

using namespace std;

void ExibeSaldo(Conta& conta) {
  
  cout<<"O saldo da conta é:"<< conta.recuperaSaldo()<<endl;
}

void sacar(Conta& conta)
{
	conta.sacar(200);
}

void FazLogin(Autenticavel& alguem, string senha)
{
	if (alguem.autentica(senha))
	{
		cout << "Login realizado com sucesso" << endl;
	}
	else
		cout << "Senha inválida" << endl;
}

int main() {

  Titular titular_umaConta("Marcelo", Cpf("123.456.789"), "umasenha");
  ContaPoupanca umaConta("123456", titular_umaConta);
  umaConta.depositar(500);
  //sacar(umaConta);
  //umaConta.sacar(200); // foi comentado para testar o modificador virtual
  //ExibeSaldo(umaConta);

  
  Titular titular_umaOutraConta("Antonio", Cpf("12345"), "umaoutrasenha");
  //ContaCorrente umaOutraConta = new ContaCorrente("123", titular_umaOutraConta);
  ContaCorrente umaOutraConta("123", titular_umaOutraConta);
  //umaOutraConta->depositar(300);
  umaOutraConta.depositar(500);
  //umaOutraConta->sacar(200);
  //sacar(umaOutraConta);
  umaOutraConta.transferir(umaConta, 200);
  ExibeSaldo(umaConta);
  ExibeSaldo(umaOutraConta);
  //delete(umaOutraConta);

  cout<< "O número de contas é: " << Conta::recuperaNumeroContas() << endl;

  cout<< "Titular de uma Conta é: " << titular_umaConta.recuperaNome() << endl;

  cout << "Titular de uma outra Conta é: " << titular_umaOutraConta.recuperaNome() << endl;

  Caixa funcionario("Dias Vinicius", Cpf("123.456.789-10"),  1000);

  cout << "CPF de uma Conta é: " << titular_umaOutraConta.recuperaNome() << endl;


  return 0;
}

