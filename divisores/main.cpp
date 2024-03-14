#include <iostream>
#include <cmath>
using namespace std;

/* Sabendo que para que o número de divisores de um número seja extamante
igual a 3 temos que e_n + 1 = 3, ou seja, o número é primo ao quadrado. 
Veridicaremos isso com o Crivo de Erastótones, apar faze-lo foram usados
os passos do site: 
https://matematicando.net.br/o-crivo-de-eratostenes-numeros-primos/*/

int crivoErastotones(long long nzinho){
    if (nzinho <= 1)return false;
    if (nzinho <= 3)return true;
    if (nzinho == 5)return true;
    if (nzinho == 7)return true;
    if (nzinho % 2 == 0)return false; 
    if (nzinho % 3 == 0)return false; 
    if (nzinho % 5 == 0)return false;
    return true;
}

int primoQuadrado(long long n){
    long long raiz = sqrt(n);
    return raiz * raiz == n && crivoErastotones(raiz);
}

int main(){
    /* Leitura de informações*/
    long long qtdNumeros;
    cin >> qtdNumeros;

    /* Leitura de cada número*/
    long long Num;
    for (long long i = 0; i < qtdNumeros;i++){
        cin >> Num;
        cout << primoQuadrado(Num);
    }
    cout << endl;
}