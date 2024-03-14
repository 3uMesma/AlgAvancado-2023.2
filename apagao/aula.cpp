#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* A classe usada foi a que o professor mostrou em sala*/
class UnionFind{
    /* Definição da estrutura*/
    private:
        typedef vector<long long int> vi;
        vi p;
        vi rank;
    public:
        /* Estruturando o vetor quando a gente criar o objeto, eles serão no formato: [0, 1, 2, 3, ...]*/
        UnionFind (long long int N){
            /* Todos começam com rank 0 e sem pais*/
            rank.assign (N, 0); p.assign (N, 0);
            for (long long int i = 0; i < N; i++){
                p[i] = i;
            }
        }
        /* Encontrando os representantes de um nó*/
        int findSet(long long int i){
            if (p[i] == i){
                return i;
            }
            /* Utilizei isso para reduzuir o tempo*/
            return p[i] = findSet(p[i]);
        }
        /* função curtinha só pra organizar o código, ela verifica se os representantes são iguais ou não,
        pois nesse caso formaria um ciclo e não faria parte da Minimum Spaning Tree (MST)*/
        bool isSameSet(long long int i, long long int j){
            return (findSet(i) == findSet(j));
        }
        /* Unindo dois conjuntos em um só. Com base no rank, decide qual conjunto deve ser anexado a outro.
        O conjunto com menor classificação (rank) será anexado ao conjunto com maior classificação para 
        otimizar nosso programa*/
        void unionSet (long long int i, long long int j){
            if (!isSameSet(i, j)){
                int x = findSet(i);
                int y = findSet(j);

                if (rank[x] > rank[y]){
                    p[y] = x;
                }
                else{
                    p[x] = p[y];
                    if (rank[x] == rank[y]){
                        rank[y] = rank[y]+ 1;
                    }
                }
            }
        }
};

/* Criando a estrutura do nó*/
struct No {
    long long origem, destino, peso;
    /* Já ajeitando na estrutura quando chamar a função No*/
    No(long long origem, long long destino, long long peso) : origem(origem), destino(destino), peso(peso) {}
    /* Função para comparar, ela "sobrescreve" a função do <, para comprara  pelos pesos do nó*/
    bool operator<(const No& outro) const {
        return peso < outro.peso;
    }

};

/* Função que aplica o algoritmo de Kruskal*/
long long Kruskal(vector<No>& nos, long long numVertices){
    /* Ordena os nós em ordem crescente de peso*/
    sort(nos.begin(), nos.end());

    /* Cria a estrutura para o UnionFind e para contar a soma mínima*/
    UnionFind uf(numVertices+1);
    long long minSum = 0;

    /* Percorrendo todos os nós, verifica se possuem os mesmos representantes, caso contrário, os une
    e aumenta a soma mínima pois ele faz parte da MST*/
    for (const No& no_atual : nos){
        // cout << "Entrou no for" << endl;
        if (!uf.isSameSet(no_atual.origem, no_atual.destino)){
            uf.unionSet(no_atual.origem, no_atual.destino);
            minSum += no_atual.peso;
        }
    }
    // cout << "Saiu do for" << endl;
    /* Lógica para verificar se não é posśivel que todas as salas se conectem ao gerador*/
    for (long long i = 2; i <= numVertices; i++) {
        /* Verifica se a sala atual, consegue se concetar a sala 1, onde está o gerador*/
        if (!uf.isSameSet(i, 1)) {
            return -1;
        }
    }

    return minSum;
}

int main(){
    /* Lendo informações*/
    long long numVertices, numArestas;
    cin >> numVertices >> numArestas;

    /* Cria um vetor de nós*/
    vector<No> nos;
    for (long long i = 0; i < numArestas; i++){
        long long origem, destino, peso;
        cin >> origem >> destino >> peso;
        /* Adicionando o nó no vetor*/
        nos.push_back(No(origem, destino, peso));
    }

    /* Calculando o menor caminho pela MST*/
    long long minSum = Kruskal(nos, numVertices);
    cout << minSum << endl;
}
