#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* Função pra debugar*/
void imprimeMatriz(vector<vector<int>> matrizAdj){
    for (int i = 0; i < matrizAdj.size(); i++){
        for (int j = 0; j < matrizAdj[i].size(); j++){
            cout << matrizAdj[i][j] << " ";
        }
        cout << endl;
    }
}

/* Fazendo um algoritmo para o caixeiro viajente, no caso, Problema da Salamandra Viajante (PSV)*/
int auxSalamandraViajante(vector<vector<int>> &matrizAdj, vector<vector<int>> &dp, int mascara,
                            int lagoAtual){
    int lagos = matrizAdj.size();

    /* Condição de parada: se só tem dois lagos, a distancia é a distancia entre eles*/
    if (mascara == (1 | (1 << lagoAtual))){
        /* Se não existe caminho entre lago 1 e lagoAtual, dist é igula a -1*/
        if(matrizAdj[0][lagoAtual] == 0){
            return -1;
        }
        /* Caso contrário, a distância é a que está na matriz*/
        return dp[mascara][lagoAtual] = matrizAdj[0][lagoAtual];
    }

    /* Se subconjunto já foi analisado, não vamos calcular novamente, vamos aproveitar o que já
    tem calculado*/
    if (dp[mascara][lagoAtual] != 0) {
        return dp[mascara][lagoAtual];
    }

    /* Deixando a distância negativa para calcular a partir do mínimo*/
    dp[mascara][lagoAtual] = -1;

    for (int i = 1; i < lagos; i++) {
        /* Verificando se: o vértice i já não foi visitado, a distância na matriz é diferente de 0, 
        ou seja, há um caminho, a minima distÂncia é -1, pois nesse caso, o min nn pode ser calculado*/
        if (((mascara >> i) & 1) != 0 && matrizAdj[i][lagoAtual] != 0 && auxSalamandraViajante(matrizAdj, 
        dp, mascara ^ ( 1 << lagoAtual), i) != -1){
            /* Com todas as verificações feitas podemos calcular o min*/
            /* Pra evitar erros, verificamos se não é -1*/
            int possivelCaminho = matrizAdj[i][lagoAtual] + auxSalamandraViajante(matrizAdj, dp, 
            mascara ^ ( 1 << lagoAtual), i);
            if (dp[mascara][lagoAtual] == -1){
                dp[mascara][lagoAtual] = possivelCaminho;
            }
            else{
                dp[mascara][lagoAtual] = min(dp[mascara][lagoAtual], possivelCaminho);
            }
        }
    }
    return dp[mascara][lagoAtual];
}
/* Função auxiliar para tornar todos os elementos de uma matriz igual a zero*/
void matrizNula(vector<vector<int>> &matriz){
    for (int i = 0; i < matriz.size(); i++){
        for(int j = 0; j < matriz[i].size(); j++){
            matriz[i][j] = 0;
        }
    }
}

int salamandraViajante(vector<vector<int>> &matrizAdj){
    /* Criando dp a partir da memoização. Criamos uma máscara com N bits definidos como 1. Isso 
    representa todas as possíveis combinações de vértices visitados (1 << lagos). Preenchemos todos 
    os valores com 0, indicando que nenhum cálculo foi realizado até o momento*/
    int lagos = matrizAdj.size();
    vector<vector<int>> dp ((1 << (lagos+1) - 1), vector<int>(lagos));
    matrizNula(dp);

    int minDistTotal = -1;

    for (int i = 1; i < lagos; i++) {
        /* Fazendo verificação para -1*/
        int minDistLocal = auxSalamandraViajante(matrizAdj, dp, (1 << lagos) -1, i);
        if (minDistLocal != -1){
            /* Se ela nn mudou*/
            if (minDistTotal == -1){
                minDistTotal = minDistLocal;
                }
            else{
                minDistTotal = min(minDistLocal, minDistTotal);
            }
        }
    }
    return minDistTotal;
}

int main(){
    /* Lendo a quantidade de lagos e trilhas*/
    int lagos, trilhas;
    cin >> lagos >> trilhas;

    /* Lendo as conexões entre eles e salvando-as em uma matriz de adjacencias*/
    vector<vector<int>> matrizAdj(lagos, vector<int>(lagos));
    int v1, v2, dist; /* vertice 1 e 2*/
    for (int i = 0; i < trilhas; i++){
        cin >> v1 >> v2 >> dist;
        /* Coloca nas duas posições, pois a matriz é simétrica*/
        matrizAdj[v1-1][v2-1] = dist;
        matrizAdj[v2-1][v1-1] = dist;
    }

    int resp = salamandraViajante(matrizAdj);
    cout << resp << endl;

    return 0;
}