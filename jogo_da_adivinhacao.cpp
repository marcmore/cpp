#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std; 

int main()

{
       cout << "**************************************" << endl;
       cout << "* Bem-vindos ao jogo da adivinhação! *" << endl;
       cout << "**************************************" << endl; 

       char nivel;
       int numero_tentativas; 

       cout << "Escolha o seu nivel de dificuldade" << endl;
       cout << "Fácil (F), Médio (M) ou Dificil (D)" << endl;
       cin >> nivel;

 

       if (nivel == 'F') {
             numero_tentativas = 15;
       }
       else if (nivel == 'M') {
             numero_tentativas = 10;
       }
       else{
             numero_tentativas = 5;
       } 

       srand(time(NULL)); // semente do número aleatório
       const int NUMERO_SECRETO = rand() %100; 

       bool nao_acertou = true;
       int tentativas = 0;
       double pontos = 1000.0;
       double pontos_perdidos = 0.0; 

       for (tentativas = 1; tentativas <= numero_tentativas; tentativas++) {

             int chute;
             cout << "Tentativa " << tentativas << endl;
             cout << "Qual seu chute? ";
             cin >> chute; 

             pontos_perdidos = abs((chute - NUMERO_SECRETO)) / 2.0;
             pontos = pontos - pontos_perdidos; 

             cout << "O valor do seu chute é: " << chute << endl;
             bool acertou = chute == NUMERO_SECRETO;
             bool maior = chute > NUMERO_SECRETO; 

             if (acertou)
             {
                    cout << "Parabéns! Você acertou o número secreto!" << endl;
                    nao_acertou = false;
                    break;
             }
             else if (maior)
             {
                    cout << "Seu chute foi maior que o número secreto!" << endl;
             }
             else
             {
                    cout << "Seu chute foi menor que o número secreto!" << endl;
             }
       }
       cout << "Fim de jogo!" << endl; 

       if (nao_acertou) {
             cout << "Voce perdeu! Tente novamente!" << endl;
       }
       else {
             cout << "Você acertou o número secreto em " << tentativas << " tentativas" << endl;
             cout.precision(2);
             cout << fixed;
             cout << "Sua pontuação foi de  " << pontos << " pontos." << endl;
       }     

}