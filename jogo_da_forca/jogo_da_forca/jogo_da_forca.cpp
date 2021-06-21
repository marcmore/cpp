// jogo_da_forca.cpp : This file contains the 'main' function. Program execution begins and ends there.
//const -> (definido no arquivo da função)não deixa que a variável seja alterada, coloca em funções para que a variavel seja usada como somente leitura
//extern std::string palavra_secreta;(definido no arquivo da função) // usa o extern para avisar que essa variável já está declarada em outra lugar
//#pragma once (definido no hpp) // usa - se pragma once para em cabeçalho para avisar que esse arquivo seja incluido apenas uma vez durante a compilação
// inline -> ocorre somente se a análise de custo-benefício do compilador mostrar que vale a pena. A expansão embutida minimiza a sobrecarga de chamada de função com o custo potencial do tamanho de código maior.
//vector ou new int aloca espaço de memoria na Heap, onde costuma se usar quando há necessidade de bastante espaço, só que é um processo mais custoso, exige mais instruções do processador, podendo penalizar o dsempenho do programa
//já stack, quando se usa array[5] por exemplo, vc já define um lugar especifico na stack onde é menos custoso

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "nao_acertou.hpp"
#include "letra_existe.hpp"
#include "nao_enforcou.hpp"
#include "imprime_cabecalho.hpp"
#include "imprime_erros.hpp"
#include "imprime_palavra.hpp"
#include "chuta.hpp"
#include "le_arquivo.hpp"
#include "salva_arquivo.hpp"
#include "adiciona_palavra.hpp"
#include "sorteia_palavra.hpp"

using namespace std;
using namespace Forca;

static string palavra_secreta; // static fala que essa variável só existe nessa translation unit, ou seja, só nesse arquivo, se essa variável for declarada em outra função ela não será reconhecida
static map<char, bool> chutou;
static vector<char> chutes_errados;

int main()
{
	imprime_cabecalho();

	//le_arquivo();

	palavra_secreta = sorteia_palavra();
	
	while (nao_acertou(palavra_secreta,chutou) && chutes_errados.size() < 5) {

		imprime_erros(chutes_errados);

		imprime_palavra(palavra_secreta,chutou);
		
		chuta(chutou,chutes_errados,palavra_secreta);

	}

	cout << "Fim de jogo!" << endl;
	cout << "A palavra secreta era: " << palavra_secreta << endl;
	if (nao_acertou(palavra_secreta, chutou)) {
		cout << "Você perdeu! Tente novamente!" << endl;
	}
	else {
		cout << "Parabéns! Você acertou a palavra secreta!" << endl;

		cout << "Você deseja adicionar uma nova palavra ao banco? (S/N)" << endl;
		char resposta;
		cin >> resposta;

		if (resposta == 'S') {
			adiciona_palavra();
		}
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file