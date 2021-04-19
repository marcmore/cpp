// jogo_da_forca.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;

string palavra_secreta = "MELANCIA";
map<char, bool> chutou;
vector<char> chutes_errados;

bool letra_existe(char chute) {
	
	for (char letra : palavra_secreta) {
		if (chute == letra) {
			return true;
		}
	}
	return false;
}

bool nao_acertou() {
	for (char letra : palavra_secreta) {
		if (!chutou[letra]) {
			return true;
		}
	}
	return false;
}

bool nao_enforcou() {
	return chutes_errados.size() < 5;
}

void imprime_cabecalho() {
	cout << "*********************" << endl;
	cout << "*** Jogo da Forca ***" << endl;
	cout << "*********************" << endl;
	cout << endl;
}

void imprime_erros() {
	cout << "Chutes errados: ";
	for (char letra : chutes_errados) {
		cout << letra << " ";
	}
	cout << endl;
}

void imprime_palavra() {
	for (char letra : palavra_secreta) {
		if (chutou[letra]) {
			cout << letra << " ";
		}
		else {
			cout << "_ ";
		}
	}
	cout << endl;
}

void chuta() {
	cout << "Seu chute: ";
	char chute;
	cin >> chute;

	chutou[chute] = true;

	if (letra_existe(chute)) {
		cout << "Voc� acertou! Seu chute est� na palavra." << endl;
	}
	else {
		cout << "Voc� errou! Seu chute n�o est� na palavra." << endl;
		chutes_errados.push_back(chute);
	}
	cout << endl;
}

vector<string> le_arquivo() {
	ifstream arquivo;
	arquivo.open("palavras.txt");

	if (arquivo.is_open()) {

		int quantidade_palavras;
		arquivo >> quantidade_palavras;

		vector<string> palavras_do_arquivo;

		for (int i = 0; i < quantidade_palavras; i++) {
			string palavra_lida;
			arquivo >> palavra_lida;
			palavras_do_arquivo.push_back(palavra_lida);
		}

		arquivo.close();
		return palavras_do_arquivo;

	}
	else {
		cout << "N�o foi poss�vel acessar o banco de palavras." << endl;
		exit(0);
	}
}

void sorteia_palavra() {
	vector<string> palavras = le_arquivo();

	srand(time(NULL));
	int indice_sorteado = rand() % palavras.size();

	palavra_secreta = palavras[indice_sorteado];
}

void salva_arquivo(vector<string> nova_lista) {
	ofstream arquivo;
	arquivo.open("palavras.txt");

	if (arquivo.is_open()) {
		arquivo << nova_lista.size() << endl;
		
		for (string palavra : nova_lista) {
			arquivo << palavra << endl;
		}

		arquivo.close();
	}
	else {
		cout << "N�o foi poss�vel acessar o banco de palavras." << endl;
		exit(0);
	}
}

void adiciona_palavra() {
	cout << "Digite a nova palavra, usando letras mai�sculas." << endl;
	string nova_palavra;
	cin >> nova_palavra;

	vector<string> lista_palavras = le_arquivo();
	lista_palavras.push_back(nova_palavra);

	salva_arquivo(lista_palavras);

}

int main()
{
	imprime_cabecalho();

	le_arquivo();

	sorteia_palavra();
	
	while (nao_acertou() && nao_enforcou()) {

		imprime_erros();

		imprime_palavra();
		
		chuta();

	}

	cout << "Fim de jogo!" << endl;
	cout << "A palavra secreta era: " << palavra_secreta << endl;
	if (nao_acertou()) {
		cout << "Voc� perdeu! Tente novamente!" << endl;
	}
	else {
		cout << "Parab�ns! Voc� acertou a palavra secreta!" << endl;

		cout << "Voc� deseja adicionar uma nova palavra ao banco? (S/N)" << endl;
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
// jogo_da_forca.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;

string palavra_secreta = "MELANCIA";
map<char, bool> chutou;
vector<char> chutes_errados;

bool letra_existe(char chute) {
	
	for (char letra : palavra_secreta) {
		if (chute == letra) {
			return true;
		}
	}
	return false;
}

bool nao_acertou() {
	for (char letra : palavra_secreta) {
		if (!chutou[letra]) {
			return true;
		}
	}
	return false;
}

bool nao_enforcou() {
	return chutes_errados.size() < 5;
}

void imprime_cabecalho() {
	cout << "*********************" << endl;
	cout << "*** Jogo da Forca ***" << endl;
	cout << "*********************" << endl;
	cout << endl;
}

void imprime_erros() {
	cout << "Chutes errados: ";
	for (char letra : chutes_errados) {
		cout << letra << " ";
	}
	cout << endl;
}

void imprime_palavra() {
	for (char letra : palavra_secreta) {
		if (chutou[letra]) {
			cout << letra << " ";
		}
		else {
			cout << "_ ";
		}
	}
	cout << endl;
}

void chuta() {
	cout << "Seu chute: ";
	char chute;
	cin >> chute;

	chutou[chute] = true;

	if (letra_existe(chute)) {
		cout << "Voc� acertou! Seu chute est� na palavra." << endl;
	}
	else {
		cout << "Voc� errou! Seu chute n�o est� na palavra." << endl;
		chutes_errados.push_back(chute);
	}
	cout << endl;
}

vector<string> le_arquivo() {
	ifstream arquivo;
	arquivo.open("palavras.txt");

	if (arquivo.is_open()) {

		int quantidade_palavras;
		arquivo >> quantidade_palavras;

		vector<string> palavras_do_arquivo;

		for (int i = 0; i < quantidade_palavras; i++) {
			string palavra_lida;
			arquivo >> palavra_lida;
			palavras_do_arquivo.push_back(palavra_lida);
		}

		arquivo.close();
		return palavras_do_arquivo;

	}
	else {
		cout << "N�o foi poss�vel acessar o banco de palavras." << endl;
		exit(0);
	}
}

void sorteia_palavra() {
	vector<string> palavras = le_arquivo();

	srand(time(NULL));
	int indice_sorteado = rand() % palavras.size();

	palavra_secreta = palavras[indice_sorteado];
}

void salva_arquivo(vector<string> nova_lista) {
	ofstream arquivo;
	arquivo.open("palavras.txt");

	if (arquivo.is_open()) {
		arquivo << nova_lista.size() << endl;
		
		for (string palavra : nova_lista) {
			arquivo << palavra << endl;
		}

		arquivo.close();
	}
	else {
		cout << "N�o foi poss�vel acessar o banco de palavras." << endl;
		exit(0);
	}
}

void adiciona_palavra() {
	cout << "Digite a nova palavra, usando letras mai�sculas." << endl;
	string nova_palavra;
	cin >> nova_palavra;

	vector<string> lista_palavras = le_arquivo();
	lista_palavras.push_back(nova_palavra);

	salva_arquivo(lista_palavras);

}

int main()
{
	imprime_cabecalho();

	le_arquivo();

	sorteia_palavra();
	
	while (nao_acertou() && nao_enforcou()) {

		imprime_erros();

		imprime_palavra();
		
		chuta();

	}

	cout << "Fim de jogo!" << endl;
	cout << "A palavra secreta era: " << palavra_secreta << endl;
	if (nao_acertou()) {
		cout << "Voc� perdeu! Tente novamente!" << endl;
	}
	else {
		cout << "Parab�ns! Voc� acertou a palavra secreta!" << endl;

		cout << "Voc� deseja adicionar uma nova palavra ao banco? (S/N)" << endl;
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
