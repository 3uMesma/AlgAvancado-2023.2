#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

/* Lógica do Programa: escolhi a estrutura unorderd map por sua rapidez na buscae pela falta
de necessidade de ter os dados ordenados. No mapa, nossa chave de busca será o número de 
matrícula e ela guardará a informação de qual disciplina o aluno está cadastrado. Ao fazer a
verificação de matrículas repetidas, vamos só analisar se a matrícula já está no sistema e se
está no mesmo curso ou em outro*/
int main() {
    /* Criando a estrutura, armazena matrícula -> curso*/
    unordered_map<int, int> mapaEstudantil;
    /* Criando a estrutura, armazena curso -> quantidade de matrículas. Dessa vez, usamos
    um mapa ordenado pois a saída é em ordem crescente de curso*/
    map<int, int> matriculasTotais; 

    /* Lendo as informações do usuário*/
    int qtdCursos;
    cin >> qtdCursos;

    for (int i = 0; i < qtdCursos; i++){

        int qtdMatriculas;
        cin >> qtdMatriculas;
        bool isDuplicate = false;

        /* Lendo todas as matrículas do curso*/
        for (int j = 0; j < qtdMatriculas; j++){

            int matricula;
            cin >> matricula;
            int curso = i;

            /* Verificando se a matrícula já existe no mapa*/
            if (!isDuplicate && mapaEstudantil.find(matricula) != mapaEstudantil.end()){
                if (mapaEstudantil[matricula] != curso){
                    /* Estudante tentou se matricular em outro curso*/
                    matriculasTotais[mapaEstudantil[matricula]]--;
                    mapaEstudantil.erase(matricula);
                    isDuplicate = true;
                }
            }
            /* Caso o estudante ainda não esteja no sistema, incluir-lo*/
            else{
                if (!isDuplicate) { // Evitar contagem adicional se já é duplicado
                    matriculasTotais[curso]++;
                }
                mapaEstudantil[matricula] = curso;
            }
        }
    }

    
    /* Exibindo a quantidade de matrículas por curso*/
    for (int i = 0; i < qtdCursos; i++) {
        cout << matriculasTotais[i] << " ";
    }
    cout << endl;

    return 0;
}