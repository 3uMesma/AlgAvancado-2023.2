#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minGuardas(vector<int>& posicaoEstatuas, int maxDistGuarda) {
    /* Inicializando o contador*/
    int guardas = 0;
    /* Essa conta calcula o número máximo de estátuas protegidas. Por exemplo, 
    se o guarda pode andar apenas uma posição, então ele pode proteger até 3
    estátuas, se elas estiverem todas juntas*/
    int maxEstuatuasProtegidas = (maxDistGuarda * 2);
    int i = 0;

    while (i < posicaoEstatuas.size()) {
        int posicaoAtual = posicaoEstatuas[i];
        /* Adicionar um guarda pois no mínimo ele deve proteger uma estátua*/
        guardas++;

        /* Mover para a pŕoxima posição que não está protegida pelo guarda. Aqui, 
        verificamos se o elemento atual que foi analisadp é o último, para evitar
        seg fault e vemos se a próxima estátua também está protegida pelo guarda
        ou se ele precisa de um novo guarda para ela*/
        while ((i < posicaoEstatuas.size()) && 
        (posicaoAtual + maxEstuatuasProtegidas) >= posicaoEstatuas[i+1]) {
            i++;
        }
        i++;
    } 

    return guardas;
}

int main() {
    /* Lendo do usuário as informações iniciais*/
    int numEstatuas, maxDistGuarda;
    cin >> numEstatuas >> maxDistGuarda;

    /* Criando o vetor e lendo as informações das posições*/
    vector<int> posicaoEstatuas(numEstatuas);
    for (int i = 0; i < numEstatuas; ++i) {
        cin >> posicaoEstatuas[i];
    }

    int minGuards = minGuardas(posicaoEstatuas, maxDistGuarda);
    cout << minGuards << endl;

    return 0;
}