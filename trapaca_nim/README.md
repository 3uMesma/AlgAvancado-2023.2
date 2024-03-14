# Nim Adulterado
Você provavelmente conhece o Jogo de Nim. Existem N pilhas, cada uma com uma quantidade ai de pedras. Dois jogadores se alternam em turnos para jogar. Em cada passo, o jogador escolhe uma pilha e remove quantas pedras dessa pilha ele quiser (desde que seja maior que zero). O jogador que não conseguir fazer nenhuma jogada (ou seja, quando todas as pilhas estão sem pedras) perde o jogo.

Após ser derrotado por Vina, Wellington Rato planeja sua vingança. Para isso, ele a desafiou para um jogo de Nim, mas com algumas mudanças. Wellington Rato quer que sua vitória seja garantida, e, para isso, ele alterou um pouco o jogo. Ele definiu duas regras adicionais:

1. Ele começa jogando;
2. Antes do jogo iniciar, ele pode escolher algumas pilhas (possivelmente zero), e adicionar uma pedra em cada pilha escolhida.

Qual a quantidade mínima de pilhas que ele precisa alterar para que sua vitória seja garantida? É garantido que ele consegue ganhar com essas alterações.

## Entrada
A primeira linha contem um inteiro T (1 ≤ T ≤ 10): a quantidade de casos de teste. Para cada caso de teste, a primeira linha contem um inteiro n (1 ≤ n ≤ 105), a quantidade de pilhas do jogo. A próxima linha possui n inteiros a1, . . . , an (1 ≤ ai ≤ 109): a quantidade de pedras da pilha i.

## Saída
A menor quantidade de pilhas que Wellington Rato precisa adulterar para garantir sua vitória.