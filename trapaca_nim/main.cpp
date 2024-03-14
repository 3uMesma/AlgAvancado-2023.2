#include <iostream>
#include <vector>
using namespace std;

int nim_adulterado(vector<int> pilhas){
    /* Se a soma do nim for igual a 0, perdemos o jogo, caso contrário iremos ganhar.
    Essa soma é calculado a partir dos valores binários da quantidade de pedras de 
    cada pilha*/
    /* Pegando o valor binário de cada pilha e calculando a soma*/
    int soma = 0;
    for(int i = 0; i < pilhas.size(); i++){
        soma = soma ^ pilhas[i];
    }
    return soma;
}

int main(){
    /* Lendo as principais informações*/
    int numRodadas;
    cin >> numRodadas;

    for (int i = 0; i < numRodadas; i++){
        int numPilhas;
        cin >> numPilhas;

        vector<int> pilhas(numPilhas);

        for (int j = 0; j < numPilhas; j++){
            cin >> pilhas[j];
        }
        if (nim_adulterado(pilhas) == 0){
            cout << 1 << endl;
        }
        else{
            cout << 0 << endl;
        }
    }
    return 0;
}