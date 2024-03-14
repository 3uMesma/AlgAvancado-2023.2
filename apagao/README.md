# Apagão
A Semana Brasileira de Computação (SBC) está chegando! Com medo de ocorrer um apagão, a organização da SBC quer que todas as salas recebam energia. Para isso, todas devem estar conectadas, direta ou indiretamente, ao gerador, localizado na sala 1. Algumas salas possuem conexões com outras por meio de fios de energia de determinados comprimentos.

A organização da SBC agora quer saber o menor custo de conexão possível para deixar todas as salas ligadas, direta ou indiretamente, ao gerador. O custo de conexão é igual à soma do comprimento de todos os fios utilizados. Como escolher os melhores fios de conexão para minimizar o custo total? Quando é impossível conectar todas as salas ao gerador?

## Entrada
A primeira linha de entrada contem dois inteiros n e m (1 ≤ n ≤ 105, 1 ≤ m ≤ 2 · 105): a quantidade de salas e a quantidade de ligações entre elas. Cada uma das próximas m linhas contem três inteiros u, v e c (1 ≤ u, v ≤ n, 1 ≤ c ≤ 109 ), informando que existe um fio de energia que conecta (bidirecionalmente) as salas u e v com comprimento c. É garantido ´
que não terá mais de uma conexão entre as mesmas duas salas na entrada.

## Saída
A menor soma possível para conectar todas as salas ao gerador de forma direta ou indireta. Caso seja impossível conectar todas as salas ao gerador, imprime −1.