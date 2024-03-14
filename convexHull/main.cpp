#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;

/* Criando uma estrutura para as coordenadas*/
struct Ponto{
    long long x, y;

    /* Redefinindo a comparação, no caso o maior vai ser o que tiver maior x e o 
    critério de desempate é o y*/
    bool operator<(Ponto p)
    {
        return x < p.x || (x == p.x && y < p.y);
    }
};

/* Produto vetorial entre dois vetores*/
long long produtoVetorial(Ponto A, Ponto B, Ponto C){
    return ((A.x - C.x) * (B.y - C.y)) - ((A.y - C.y) * (B.x - C.x));
}

/* Distãncia entre dois pontos*/
double distPontos(Ponto A, Ponto B)
{
    return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}

/* Usando convexHull para encontrar a forma geométrica*/
vector<Ponto> convexHull(vector<Ponto> A){
    long long  n = A.size();
    long long  k = 0; /* contador para o casco convexo*/
    
    /* Se o número de pontos for 3 ou menos, o casco convexo é simplesmente o 
    conjunto de pontos, então retorna o vetor original.*/
    if (n <= 3)
        return A;
 
    /* Cria um vetor para armazenar os pontos do casco convexo. */
    vector<Ponto> cascoConvexo(2 * n); 
 
    /* Ordena os pontos*/
    sort(A.begin(), A.end());
 
    /* Constroi a parte inferior do casco convexo.*/
    for (long long i = 0; i < n; ++i) {
        /* Enquanto os pontos anteriores no casco convexo formam uma curva 
        anti-horária com o próximo ponto, remove o último ponto adicionado.*/
        while (k >= 2 && produtoVetorial(cascoConvexo[k - 2], cascoConvexo[k - 1], A[i]) <= 0){
            k--;
        }
        /* Adiciona o ponto atual ao casco convexo.*/
        cascoConvexo[k++] = A[i];
    }
 
    /* Constrói a parte superior do casco convexo. Funciona de forma análoga a 
    parte inferior*/
    for (size_t i = n - 1, t = k + 1; i > 0; --i) {
        while (k >= t && produtoVetorial(cascoConvexo[k - 2], cascoConvexo[k - 1], A[i - 1]) <= 0){
            k--;
        }
        cascoConvexo[k++] = A[i - 1];
    }
 
    /* Redimensiona o vetor para o tamanho final do casco convexo.*/
    cascoConvexo.resize(k - 1);
 
    return cascoConvexo;
}

double perimetro(vector<Ponto> cascoConvexo)
{
    double pmetro = 0.0;
 
    /* Calculando distância entre pontos*/
    for (long long i = 0; i < cascoConvexo.size() - 1; i++) {
        pmetro += distPontos(cascoConvexo[i], cascoConvexo[i + 1]);
    }
 
    // Add the distance between first and last point
    pmetro += distPontos(cascoConvexo[0], cascoConvexo[cascoConvexo.size() - 1]);
 
    return pmetro;
}

int main(){
    int pontos;
    cin >> pontos;
    long long x, y;
    vector<Ponto> coordenadas;

    for (int i = 0; i < pontos; i++){
        cin >> x >> y;
        coordenadas.push_back({x, y});
    }

    /* Encontrando a forma geométrica*/
    vector<Ponto> cascaConvexa = convexHull(coordenadas);
    cout << fixed<< setprecision(6) << perimetro(cascaConvexa) << endl;
    return 0;
}


