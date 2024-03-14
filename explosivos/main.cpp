#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* Aproveitando a função do código dos guardas, para calcular se o raio suposto
é o raio mínimo. Essa função vai verificar se, a partir de um raio, é possível
explodir um número x de estátuas com suas distâncias*/
int minBombas(vector<int>& posicaoEstatuas, int maxRaioBombas) {
    /* Inicializando o contador*/
    int bombas = 0;
    /* Essa conta calcula o número máximo de estátuas protegidas. Por exemplo, 
    se o guarda pode andar apenas uma posição, então ele pode proteger até 3
    estátuas, se elas estiverem todas juntas*/
    int maxEstuatuasExplodidas = (maxRaioBombas * 2);
    int i = 0;

    while (i < posicaoEstatuas.size()) {
        int posicaoAtual = posicaoEstatuas[i];
        /* Adicionar um guarda pois no mínimo ele deve proteger uma estátua*/
        bombas++;

        /* Mover para a pŕoxima posição que não está protegida pelo guarda. Aqui, 
        verificamos se o elemento atual que foi analisadp é o último, para evitar
        seg fault e vemos se a próxima estátua também está protegida pelo guarda
        ou se ele precisa de um novo guarda para ela*/
        while ((i < posicaoEstatuas.size()) && 
        (posicaoAtual + maxEstuatuasExplodidas) >= posicaoEstatuas[i+1]) {
            i++;
        }
        i++;
    } 

    return bombas;
}

/* Função principal para encontar o raio mínimo de explosão*/
int minRaioExplosao(vector<int>& posicaoEstatuas, int numBombas){
    /* Esse algoritmo implementa a ideia de busca binária que é um método
    de divisão e conquista*/
    /* Vamo inicialmente setar valores mínimos e máximo absurdos para o raio
    da bomba, para poder realizar a busca*/
    int minRaio = 0;
    /* Esse é o maio raio possível pois considera a posição da primeira e última
    estátuas e divide por dois, já que o raio é para os dois lados*/
    int maxRaio = (posicaoEstatuas[posicaoEstatuas.size() - 1] - posicaoEstatuas[0])/2;
    int meio;

    /* Enquanto o raio menor não ultrapassar o maior, garantindo que retornaremos o
    menor raio*/
    while (minRaio <= maxRaio){
        meio = (minRaio + maxRaio)/2;
        /* Verificando se esse valor gerado resulta no número de bombas que temos*/
        if(minBombas(posicaoEstatuas, meio) <= numBombas){
            maxRaio = meio - 1;
        }
        /* Caso contrário, aumentar o valor mínimo*/
        else {
            minRaio = meio + 1;
        }
    }
    return minRaio;
}

int main() {
    /* Lendo as informações*/
    int numEstatuas, numBombas;
    cin >> numEstatuas >> numBombas;

    /* Salvando a localização delas*/
    vector<int> posicoes(numEstatuas);
    for (int i = 0; i < numEstatuas; ++i) {
        cin >> posicoes[i];
    }

    /* Chamando a função*/
    int raio = minRaioExplosao(posicoes, numBombas);
    cout << raio << endl;

    return 0;
}
