# Show de Baixo

O repertório que o João Baixista conhece é descrito em uma lista com n músicas. Cada música i (1, . . . , n) possui uma dificuldade di. Agora, com o repertório em mãos, ele precisa escolher algumas músicas para montar o espetáculo perfeito. Baixista acredita que, em um espetáculo perfeito, músicas consecutivas não possuem uma grande diferença de dificuldades. João inicia tocando a música 1. Ele repetirá a seguinte ação até acabarem as músicas de seu repertório:

• Caso a última música escolhida tenha sido a música i, ele pode escolher a música i+1 (caso i+1 ≤ n) ou a música i + 2 (caso i + 2 ≤ n). Nisso, um custo de |di − dj | é somado ao espetáculo, em que j é a música que ele escolheu.

João não pode alterar a ordem das músicas do repertório inicial, mas, como visto nas regras acima, ele pode pular algumas músicas no meio caso ache necessário. Note que ele sempre irá começar tocando a música 1 e irá acabar o espetáculo tocando a música n. Vamos ajudar João Baixista a encontrar o menor custo total possível, caso escolha as demais músicas de maneira ótima para o espetáculo.

## Entrada
A primeira linha de entrada possui um inteiro n (2 ≤ n ≤ 106), a quantidade de músicas no repertório. A segunda linha possui n inteiros di (1 ≤ di ≤ 109, para i = 1, . . . , n): a dificuldade de cada música.

## Saída
Um inteiro contendo o menor custo possível do espetáculo perfeito.