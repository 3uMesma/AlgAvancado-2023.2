# Abelhas
Na colmeia, cada abelha é representada por um número: a quantidade de pólen coletada pela abelha em uma missão. Por exemplo, caso uma abelha representada por um número x seja escolhida para coletar pólen, ela voltará para a colmeia com exatamente x quantidades de pólen. Uma missão nesse caso é uma ida e volta da colmeia para coletar pólen, com uma quantidade positiva (e não-nula) de abelhas.

Porém, as abelhas acabam se cansando, e nem sempre todas podem ir coletar pólen. Também é definido que o valor de uma missão é a soma do némero x de todas as abelhas que foram nela. Por exemplo, caso as abelhas escolhidas sejam representadas pelos números [2, 4, 1, 4], o valor dessa missão é 2 + 4 + 1 + 4 = 11. Isso significa que essa missão conseguirá trazer 11 unidades de pólen para a colmeia.

Queremos calcular a quantidade de valores de missão distintos para todos os subconjuntos possíveis de abelhas que podem ser escolhidas em uma missão.

## Entrada
A primeira linha de entrada contem um inteiro n (1 ≤ n ≤ 20): a quantidade total de abelhas da colmeia. A segunda linha contem n inteiros xi (1 ≤ xi ≤ 108): a quantidade de pólen transportada pela i-ésima abelha.

## Saída
Apenas um número inteiro, contendo a quantidade de somas distintas para cada subconjunto de abelha que pode ser escolhido.