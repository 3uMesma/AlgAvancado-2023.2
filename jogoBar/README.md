# Jogo de Bar
Para atrair clientes, o dono do bar pensou em um desafio para premiar quem acertasse. No desafio, cada cliente receberá dois
números inteiros n e k. O objetivo é deixar n igual a 0. Em cada passo, são possíveis dois lances:

1. Decrementar n por 1;
2. Dividir n por k, caso n seja divis´ıvel por k.

Dados os números n e k, qual a menor quantidade possível de lances para atingir n = 0?

## Entrada
A primeira linha possui um inteiro T (1 ≤ T ≤ 100): a quantidade de casos para consultar. As próximas T linhas possuem dois inteiros cada, n e k (1 ≤ n ≤ 1018, 2 ≤ k ≤ 1018).

## Saída
T linhas: para cada consulta, qual a menor quantidade de lances para levar n até 0.