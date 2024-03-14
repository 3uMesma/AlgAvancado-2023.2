# Estátuas
Por simplicidade, considere que a exposição de estátuas está ocorrendo em um corredor reto unidimensional. Ao total, são expostas n estátuas (1 ≤ n ≤ 105), cada uma situada em uma coordenada inteira xi (1 ≤ xi ≤ 109, i = 1, . . . , n).

Para evitar a obstrução de estátuas, a organização da exposição contratará guardas para protegê-las. Cada guarda consegue proteger uma distância de no máximo k (1 ≤ k ≤ 109) para ambos os lados. Por exemplo, se o guarda estiver na posição p, ele consegue proteger todas as estátuas posicionadas no intervalo fechado [p − k, p + k].

Dadas as posições das estátuas, calcularemos a quantidade mínima de guardas necessários para proteger todas as estátuas.

## Entrada
A primeira linha de entrada contêm dois inteiros n e k (1 ≤ n ≤ 105, 1 ≤ k ≤ 109): a quantidade de estátuas e a distância assegurada por cada guarda. A segunda linha contêm n inteiros distintos e ordenados xi (1 ≤ xi ≤ 109). É garantido que estes números já estão ordenados (xi < xi+1, i = 1, . . . , n − 1).

## Saída
A quantidade mínima de guardas necessários para proteger todas as estátuas.