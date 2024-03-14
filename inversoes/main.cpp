#include <bits/stdc++.h>
#include <vector>
using namespace std;

/* Lógica do programa: foi escolhido o algoritmo do MergeSort por sua estratégia de divisão e 
conquista. Ele divide o array em metades menores, ordena essas metades e, durante a mesclagem, 
conta as inversões, garantindo que todas sejam contabilizadas corretamente. Além disso, por ser
um algoritmo estável, ele preserva a ordem relativa dos elementos com valores iguais. Isso é 
importante para a verificação se o elemento à esquerda é maior que o elemento à direita. O
algoritmo impelmnetado é muito parecido com o algoritmo padrão do mergeSort*/

/* Objetivo: mesclar duas metades ordenadas de um array e contar as inversões */
long long merge(vector<long long>& vetor, vector<long long>& temp, int esq, int meio, int dir){
    int i, j, k;
    long long invercoes = 0;
 
    i = esq;
    j = meio;
    k = esq;

    /* O algoritmo percorre as duas metades do vetor, comparando os elementos e contando as 
    inversões sempre que um elemento na metade direita é menor do que um elemento na metade 
    esquerda*/
    while ((i <= meio - 1) && (j <= dir)) {
        if (vetor[i] <= vetor[j]) {
            temp[k++] = vetor[i++];
        }
        else {
            temp[k++] = vetor[j++];
            /* Contabiliza as inversões*/
            invercoes += (meio - i);
        }
    }

    /* Copia os elementos restantes da metade esquerda, se houver*/
    while (i <= meio - 1){
        temp[k++] = vetor[i++];
    }
 
    /* Copia os elementos restantes da metade direita, se houver*/
    while (j <= dir){
        temp[k++] = vetor[j++];
    }
    
    /* Atualiza o vetor original com os elementos mesclados*/
    for (i = esq; i <= dir; i++)
        vetor[i] = temp[i];
 
    return invercoes;
}

/* Função MergeSort principal. Funciona como um Merge normal*/
long long mergeSort(vector<long long>& vetor, vector<long long>& temp, int esq, int dir){
    int meio;
    long long invercoes = 0;
    if (dir > esq) {
        meio = (dir + esq) / 2;
        /* // Recursivamente ordena as metades esquerda e direita e conta as inversões*/
        invercoes += mergeSort(vetor, temp, esq, meio);
        invercoes += mergeSort(vetor, temp, meio + 1, dir);
 
        /* Combina as duas metades ordenadas e contabiliza as inversões*/
        invercoes += merge(vetor, temp, esq, meio + 1, dir);
    }
    return invercoes;
}

int main(){
    int tamVetor;
    cin >> tamVetor;

    vector<long long> vetor(tamVetor);
    for (int i = 0; i < tamVetor; i++){
        cin >> vetor[i];
    }

    vector<long long> temp(tamVetor);
    long long invercoesTotais = mergeSort(vetor, temp, 0, tamVetor - 1);
    cout << invercoesTotais << endl;

    return 0;
}