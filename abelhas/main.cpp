#include <iostream>
#include <vector>
#include <set>

using namespace std;

// Objetivo: contar as somas distintas de subconjuntos
int somas_distintas(vector<int>& polen) {
    int n = polen.size();
    // Armazenando cada soma
    set<int> somas_diferentes;

    // Loop através de todas as máscaras possíveis de subconjuntos
    for (int mascara = 1; mascara < (1 << n); ++mascara) {
        // Soma dos elementos do subconjunto
        int soma_subconjunto = 0;
        // Loop através de cada bit da máscara
        for (int bit = 0; bit < n; ++bit) {
            // Verifica se o bit atual está ligado na máscara
            if ((mascara >> bit) & 1) {
                // Adiciona o elemento à soma do subconjunto
                soma_subconjunto += polen[bit];
            }
        }
        // Insere a soma no conjunto
        somas_diferentes.insert(soma_subconjunto);
    }

    return somas_diferentes.size();
}

int main() {
    // Leitura
    int numAbelhas;
    cin >> numAbelhas;

    vector<int> polen(numAbelhas);
    for (int i = 0; i < numAbelhas; ++i) {
        cin >> polen[i];
    }

    int resultado = somas_distintas(polen);
    cout << resultado << endl;

    return 0;
}