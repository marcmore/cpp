#include <iostream>
using namespace std;

int main(){

    cout << "***********************************************************************************" << endl;
    cout << "*  BEM  VINDOS AO JOGO DA ADIVINHACAO!  *" << endl;
    cout << "***********************************************************************************" << endl;


    const int NUMERO_SECRETO = 42;

    int chute;

    bool nao_acertou = true;

    int tentativas = 0;

    while(nao_acertou){

        tentativas++;
        cout << "Tentativa " << tentativas << endl;
        
        cout << "Qual seu chute? ";
        cin >> chute;

        bool acertou = chute == NUMERO_SECRETO;
        bool maior = chute > NUMERO_SECRETO;

        if (acertou){    
            cout << "Parabens. Voce acertou o numero!!!" << endl;
            cout << "Fim de jogo!" << endl;
            cout << "Voce acertou o numero correto em " << tentativas << " tentativas" << endl;
            nao_acertou = false;
        }

        else if (maior){
            cout << "Seu chute foi maior do que o numero secreto" << endl;
        }

        else {
            cout << "Seu chute foi menor do que o numero secreto" << endl;
        }
    }

}