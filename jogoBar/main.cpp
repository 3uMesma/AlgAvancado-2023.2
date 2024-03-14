#include <iostream>
using namespace std;

long long qtdLances(long long n1, long long n2, long long resposta){
    /* Condição de parada*/
    if (n1 == 0){
        return resposta - 1;
    }
    /* O resto da divisão é a quantidade de lances*/
    resposta += n1 % n2;
    return qtdLances(n1/n2, n2, resposta + 1);
}

int main(){
    /* Leitura das informções*/
    long long jogadores;
    cin >> jogadores;
    long long n1, n2;
    for (long long i = 0; i < jogadores; i++){
        cin >> n1 >> n2;
        cout << qtdLances(n1, n2, 0) << endl;
    }
    return 0;
}