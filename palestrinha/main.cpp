#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
using namespace std;

/* Função auxiliar para comparar o segundo item de duas tuplas */
struct CompararTupla {
    bool operator()(const tuple<int, int>& a, const tuple<int, int>& b) {
        return get<1>(a) > get<1>(b); // Ordenar em ordem crescente do segundo item
    }
};

int main() {
    /* Lendo o número total de palestras */
    int numPalestras;
    cin >> numPalestras;

    /* Guardando todas as informações em um vetor de tuplas */
    vector<tuple<int, int>> Palestras;
    for (int i = 0; i < numPalestras; i++) {
        int inicio, fim;
        cin >> inicio >> fim;
        Palestras.push_back(make_tuple(inicio, fim));
    }

    /* Ordenando o vetor de tuplas em ordem crescente de término da palestra */
    sort(Palestras.begin(), Palestras.end(), [](const auto& a, const auto& b) {
        return get<1>(a) < get<1>(b);
    });

    /* Criando um contador para a quantidade máxima de palestras que poderão ser assistidas */
    int maxPalestras = 1;
    int fimUltimaPalestra = get<1>(Palestras[0]);

    /* Percorrendo nosso vetor de palestras */
    for (int i = 1; i < numPalestras; i++) {
        /* Se a próxima palestra começar após o término da última assistida */
        if (get<0>(Palestras[i]) >= fimUltimaPalestra) {
            maxPalestras++;
            fimUltimaPalestra = get<1>(Palestras[i]);
        }
    }

    /* Saída do programa */
    cout << maxPalestras << endl;

    return 0;
}
