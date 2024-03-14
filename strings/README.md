# Revisão de René
Fazer uma revisão literária pode ser uma tarefa complicada. Para facilitar seu trabalho, René criou uma lista de palavras relevantes à sua pesquisa. Sempre que ele encontra uma palavra relevante, ele a adiciona na lista. As vezes, uma palavra deixa de ser relevante, e René a remove da lista. De tempos em tempos, René pensa em uma string, e quer saber quantas palavras na lista a possuem como prefixo.

Contar palavra por palavra pode ser uma tarefa entediante (e ele ainda tem um doutorado inteiro pela frente). A tarefa do código é ajudá-lo a fazer essas consultas. Ele receberá q operações, que podem ser dos seguintes tipos:

• 1 s - Adicionar a palavra s na lista;
• 2 s - Remover a palavra s da lista;
• 3 s - Contar quantas palavras na lista (no momento atual) contêm s como prefixo.

No início, a lista de palavras está vazia. Para cada consulta do tipo 3, imprima um número inteiro, representando o resultado da consulta em uma linha única.

## Entrada
A primeira linha contem um inteiro q (1 ≤ q ≤ 106). As próximas q linhas possuem um inteiro t (1 ≤ t ≤ 3) e uma string s (1 ≤ |s| ≤ 106), representando o tipo da operação e a string a ser consultada. É garantido que a soma de comprimentos de todas as strings vão ser menores que 106, e que todas as strings a serem removidas (operação 2) pertencem a lista atual.

## Saída
Para cada consulta do tipo 3, imprime um único número: a quantidade de strings na lista de palavras atuais que possuem s como prefixo. Lembre-se que a ordem das consultas é importante!