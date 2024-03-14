# Palestrinha
Pelo elevado número de inscritos na disciplina Seminários 1, a docente responsável pelo curso adotou uma abordagem não usual
para organizar os seminários. Durante o semestre, ela convidará outros professores e pesquisadores para palestrar n seminários (1 ≤ n ≤ 105). Cada seminário terá um momento de início li e um momento de encerramento ri (1 ≤ li < ri ≤ 109).

Cada aluno pode escolher quais seminários quer assistir, e a nota de um aluno será proporcional à quantidade de palestras que ele assistir. Não é possível para o mesmo aluno assistir duas palestras ao mesmo tempo, porém pode-se começar a ver uma logo após outra encerrar - ou seja, se uma palestra i se encerra no momento ri, é possível assistir a qualquer palestra j que comece no momento lj tal que lj ≥ ri.

Qual a maior quantidade k de palestras que um aluno poderá ir, caso as escolha de modo ótimo? Note que ele não quer maximizar a quantidade de horas, mas sim a quantidade de palestras assistidas.

## Entrada
A primeira linha de entrada conterá um inteiro n (1 ≤ n ≤ 105): a quantidade de palestras. Cada uma das próximas n linhas terá dois inteiros li, ri (1 ≤ li < ri ≤ 109), os momentos de início e fim de cada palestra.

## Saída
Apenas um inteiro k: a maior quantidade possível de palestras assistidas de acordo com o enunciado.