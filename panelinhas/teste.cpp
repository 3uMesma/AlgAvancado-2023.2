#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define MAXN 200100
vector<int> grafo[MAXN];
vector<int> grafo_transposto[MAXN];
bool visitado[MAXN];
stack<int> pilha; 

// Objetivo: adicionar uma aresta
void aresta_adicionar(int vertice1, int vertice2) {
    grafo[vertice1-1].push_back(vertice2-1);
}

// Busca DFS recursiva
void grafo_DFS(int v, vector<int> &linha){
	// marcando o nó atual como visitado e guardando ele no vetor
	visitado[v] = true;
	linha.push_back(v);
	
	/* chamar recursivamente até toda a lista de adjacencias ser
    percorrida */
	for (auto i : grafo_transposto[v]) {
        if (!visitado[i]) {
            grafo_DFS(i, linha);
        }
    }
}

void grafoTransposto(int num_vertices){
    for (int v = 0; v < num_vertices; v++) {
        for (int adjacente : grafo[v]) {
            grafo_transposto[adjacente].push_back(v);
        }
    }
}

/* Objetivo: preencher a pilha Stack com os vértices do grafo em ordem
crescente de tempos de finalização */
void pilha_preencher(int v){
	// Marca o nó atual como visitado
    visitado[v] = true;

    // Chama recursivamente todos os nós adjacentes a esse vértice
    for (int vizinho : grafo[v]) {
        if (!visitado[vizinho]) {
            pilha_preencher(vizinho);
        }
    }

    // Após processar todos, coloca-los na pilha
    pilha.push(v);
}

/* Função auxiliar para setar todos os vértices iniciais
como não visitados */
void vertices_set_nao_vistados(int num_vertices){
	for(int i = 0; i < num_vertices; i++){
        visitado[i] = false;
    }
}

// Função principal que encontra os componentes fortemente conexos
void comp_fort_con(int num_vertices){
	int linhas = 0;
	vector<vector<int>> matriz;

	// marcando todos os vértices iniciais como não visitados
    vertices_set_nao_vistados(num_vertices);

	// Colocando os vértices na pilha de acordo com o tempo de processamento
	for(int i = 0; i < num_vertices; i++){
        if(visitado[i] == false){
            pilha_preencher(i);
        }
    }
	// for (int i = 0; i < num_vertices; i++){
	// 	cout << pilha.top() << " ";
	// 	pilha.pop();
	// }
	// cout << endl;
	// exit(1);

	// Gerando o grafo transposto
	grafoTransposto(num_vertices);

	// Setando novamente todos como não visitados, para a segunda busca DFS
    vertices_set_nao_vistados(num_vertices);

	/* Criando um vetor para armezenar a informação de qual grupo pertence cada 
	aluno. O -1 indica que ele não está em nenhum grupo. O primeiro grupo se
	idetifica pelo grupo 1 e dps vai incrementando*/
	vector<int> grupoAlunos (num_vertices, -1);
	int grupoAtual = 1;

	// Agora, processando todos os vértices na ordem da pilha
	int j = 0;
	while (!pilha.empty()){
		// salvamos numa variável o topo da pilha para depois retira-lo
		int vertice_atual = pilha.top();
		pilha.pop();
		// cout << vertice_atual << endl;

		if (!visitado[vertice_atual]){
			// cout << "Olá" << endl;
			vector<int> linha;
			grafo_DFS(vertice_atual, linha);
			//ordenando cada linha		
			sort(linha.begin(), linha.end());
			/* Fazendo uma verificação para que as linhas só sejam incrementadas
			caso o tamanho do vetor do resultado da busca não for zero */
			if (linha.size() > 0){
				matriz.push_back(linha);
				linhas++;
				j++;

				/* Atribuir grupo ao aluno*/
				for (int aluno : linha){
					grupoAlunos[aluno] = grupoAtual;
				}
				/* Incrementando o grupo atual*/
				grupoAtual++;
			}
		}
	}
	cout << linhas << endl;

	/* Ajustando os valores dos grupos, pois está dando diferente do corre códigos*/
	int novosGrupos = 0;
	vector<int> antigosGrupos(grupoAtual + 1, 0);
	for (int i = 0; i <= num_vertices-1; i++){
		if (antigosGrupos[grupoAlunos[i]] == 0){
			antigosGrupos[grupoAlunos[i]] = ++novosGrupos;
		}
	}

	/*Imprimindo*/
	for (int i = 0; i <= (num_vertices - 1); i++){
		cout << antigosGrupos[grupoAlunos[i]] << " ";
	}
	cout << endl;
}

int main(){
    // Lendo do usuário informações importantes
    int numAlunos, numRelacoes;
    cin >> numAlunos >> numRelacoes;

    // Lendo todas as conexões
    for (int i = 0; i < numRelacoes; i++){
        // Lendo os vértices que fazem parte de cada conexão
        int vertice1, vertice2;
        cin >> vertice1 >> vertice2;

        // Adicionando essa aresta ao grafo
        aresta_adicionar(vertice1, vertice2);
    }

	// for (int i = 0; i < numAlunos; i++){
	// 	for (int j = 0; j < grafo[i].size(); j++){
	// 		cout << grafo[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	// cout << endl;
	// cout << endl;

    // Encontrando elementos fortemente conexos
    comp_fort_con(numAlunos);
	return 0;
}