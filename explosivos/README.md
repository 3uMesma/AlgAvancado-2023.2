# Destruição das Estátuas
A exposição possui n estátuas. A i-ésima estátua está localizada na posição xi. Para realizar seu plano de destruir as estátuas, o aluno terá que comprar k explosivos. Ele sabe que cada explosivo causa uma explosão de raio r: isto é, se o explosivo for inserido na posição p, todas as estátuas no intervalo [p − r, p + r] serão destruídas. Este valor r é um número inteiro e não-negativo.

Porém, por ser apenas um estudante, ele não possui tanto dinheiro para comprar explosivos muito poderosos, e quer minimizar este poder r. Sabendo que ele irá comprar exatamente k explosivos, qual o menor poder r possível tal que ele ainda consiga explodir todas as n estátuas?

## Entrada
A primeira linha de entrada contem dois inteiros n e k (1 ≤ n, k ≤ 105): a quantidade de estátuas e a quantidade de explosivos que ele irá utilizar. A segunda linha contem n inteiros distintos e ordenados xi (1 ≤ xi ≤ 109). É garantido que estes números já estão ordenados (xi < xi+1, i = 1, . . . , n − 1).

## Saída
Imprima o menor r possível para que, caso ele posicione os k explosivos de maneira ótima, todas as estátuas sejam destruídas.