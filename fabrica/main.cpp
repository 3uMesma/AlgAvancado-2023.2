#include <iostream>
#include <vector>
using namespace std;

long long maiorLucro(vector<vector<long long>>& matriz, long long tiposProdutos, long long dias){

    /* Guardando as informações e incializando como 0*/
    vector<vector<long long>> MEMO(dias, vector<long long>(tiposProdutos, 0));

    /* percorredo todos os dias*/
    long long lucroMax = 0;
	for (int i = 0; i < dias; i++){
		// para todos os produtos
		for (int j = 0; j < tiposProdutos; j++){
			MEMO[i][j] = matriz[i][j];
            for (int k = 0; k < tiposProdutos; k++) {
                if (i > 0 && j != k) {
                    MEMO[i][j] = max(MEMO[i][j], matriz[i][j] + MEMO[i - 1][k]);
                }
            }
            lucroMax = max(lucroMax, MEMO[i][j]);
		}
	}
    return lucroMax;
}

int main(){
    /* Lendo n (dias) e K (variedade de produtos)*/
    long long dias, tiposProdutos;
    cin >> dias >> tiposProdutos;

    /* Lendo as informações da matriz*/
    vector<vector<long long>> matriz(dias, vector<long long>(tiposProdutos));
    for (int i = 0; i < dias; i++){
        for (int j = 0; j < tiposProdutos; j++){
            cin >> matriz[i][j];
        }
    }

    /* Chamando a função principal*/
    long long resultado = maiorLucro(matriz, tiposProdutos, dias);
    cout << resultado << endl;
    return 0;
}