#include <iostream>
#include <string>
#include <vector>

using namespace std;

/* Criando estrutura para a árvore*/
struct No{
    char info;
    vector<No*>filhos;
    /* Flag para ver quantas vezes a letra é usada*/
    int vezes = 0;
    No(char c) : info(c) {}
};

/* Criando uma classe para a árvore*/
class Arvore{
    private:
        No* raiz;

    public:
        /* Criar árvore*/
        Arvore(char raizInfo){
            raiz = new No(raizInfo);
        }

        No* getRaiz() {
            return raiz;
        }

        /* retorna qual filho tem a informação que procuramos, caso não tenha nenhum,
        retorna -1*/
        int buscarEntreIrmaos(char procurado, No* pai){
            if (pai == nullptr){
                return -1;
            }

            for (int i = 0; i < pai->filhos.size(); i++){
                if (pai->filhos[i]->info == procurado){
                    return i;
                }
            }

            return -1;
        }

        int addFilho(char filhoInfo, No* pai){
            /* verificando se naquela nível já não tem um dado com a mesma informação*/
            int resultadoBusca = buscarEntreIrmaos(filhoInfo, pai);

            /* adicionando um char pela primeira vez*/
            if (resultadoBusca == -1){
                No* novoNo = new No(filhoInfo);
                novoNo->vezes++;
                pai->filhos.push_back(novoNo);
                return (pai->filhos.size()) - 1;
            }
            /* caso o char já esteja na árvore*/
            pai->filhos[resultadoBusca]->vezes++;
            return resultadoBusca;
        }

        int rmvFilho(char filhoInfo, No* pai){
            /* buscando onde está o filho que queremos remover*/
            int resultadoBusca = buscarEntreIrmaos(filhoInfo, pai);

            /* Diminuindo o número de ocorrências/vezes*/
            if (resultadoBusca != -1){
                pai->filhos[resultadoBusca]->vezes--;
            }
            return resultadoBusca;
        }

        /* Adiciona toda a palavra na árvore*/
        void addPalavra(string palavra){
            /* Primeira palavra começa sempre da raiz*/
            No* raiz = getRaiz();

            /* Partindo para o próximo filho, ele está fora do for por usar a raiz*/
            int proxPosicao = addFilho(palavra[0], raiz);
            No* proxNo = raiz->filhos[proxPosicao];

            for (int i = 1; i < palavra.size(); i++){
                proxPosicao = addFilho(palavra[i], proxNo);
                proxNo = proxNo->filhos[proxPosicao];
            }
        }

        /* Remove a palavra toda da árvore*/
        void rmvPalavra(string palavra){
            No* raiz = getRaiz();

            int proxPosicao = rmvFilho(palavra[0], raiz);
            /* Caso não exista a palavra*/
            if (proxPosicao == -1){
                return;
            }

            No* proxNo = raiz->filhos[proxPosicao];
            
            for (int i = 1; i < palavra.size(); i++){
                proxPosicao = rmvFilho(palavra[i], proxNo);
                if (proxPosicao == -1){
                    return;
                }
                proxNo = proxNo->filhos[proxPosicao];
            }
        }

        int buscaPrefixo(string palavra){
            /* Começando a buscar pela raiz*/
            No* raiz = getRaiz();

            int proxPosicao = buscarEntreIrmaos(palavra[0], raiz);
            if (proxPosicao == -1){
                return 0;
            }

            No* proxNo = raiz->filhos[proxPosicao];
            
            for (int i = 1; i < palavra.size(); i++){
                proxPosicao = buscarEntreIrmaos(palavra[i], proxNo);
                if (proxPosicao == -1){
                    return 0;
                }
                proxNo = proxNo->filhos[proxPosicao];
            }
            return proxNo->vezes;
        }

        void imprimeArvore(No *raiz) {
            if (raiz == nullptr) {
                return;
            }
            
            // Imprime o conteúdo do nó
            cout << raiz->info << " (" << raiz->vezes << ")" << endl;
            // Imprime os filhos do nó
            for (No *filho : raiz->filhos) {
                imprimeArvore(filho);
        }
    }

};

int main(){
    /* Lendo informações*/
    int nPalavras;
    cin >> nPalavras;

    /* Criando a árvore*/
    Arvore arv('y');

    for (int i = 0; i < nPalavras; i++){
        int opcao;
        string palavra;
        cin >> opcao >> palavra;
        switch (opcao)
        {
        case 1:
            /* adicionar palavra na lista*/
            arv.addPalavra(palavra);
            // arv.imprimeArvore(arv.getRaiz());
            break;
        case 2:
            /* remover palavra da lista*/
            arv.rmvPalavra(palavra);
            // arv.imprimeArvore(arv.getRaiz());
            break;
        case 3:
            /* contar quantas palavras na lista contèm o mesmo sufixo*/
            cout << arv.buscaPrefixo(palavra) << endl;
            // arv.imprimeArvore(arv.getRaiz());
            break;
        default:
            break;
        }
    }
}
