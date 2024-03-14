#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

long long solvePD (long long numMusicas, vector<long long>& dificuldadeMusicas){
    /* Armazenando os menores custos, icicializando todos como 0*/
    vector<long long> menoresCustos(numMusicas, 0);
    /* Percorrendo todas as musicas*/
    for (long long i = 1; i < numMusicas; i++){
        // cout << " i: " << i << endl;
        // cout << "Valor Atual Vetor:" << dificuldadeMusicas[i] << endl;
        /* Tentando pulando 2*/
        menoresCustos[i] = LLONG_MAX;
        if (i-2 >= 0){
            menoresCustos[i] = min(menoresCustos[i], menoresCustos[i-2] + abs(dificuldadeMusicas[i] - dificuldadeMusicas[i-2]));
        }
        /* Testando pulando 1*/
        if (i-1 >= 0){
            menoresCustos[i] = min(menoresCustos[i], menoresCustos[i-1] + abs(dificuldadeMusicas[i] - dificuldadeMusicas[i-1]));
        }
    }
    /* Retorna o menor custo total*/
    return menoresCustos[numMusicas-1];
}

int main(){
    /* Leitura das informações básicas*/
    long long numMusicas;
    cin >> numMusicas;
    vector<long long> dificuldadeMusicas(numMusicas);
    for (long long i = 0; i < numMusicas; i++){
        cin >> dificuldadeMusicas[i];
    }

    long long resultado = solvePD(numMusicas, dificuldadeMusicas);
    cout << resultado << endl;

    return 0;
}