# Matrículas Abertas

O programa enumera quantos alunos estão de fato inscritos em cada curso.

As regras para matricular-se em cursos no novo sistema são as seguintes:
• Cada aluno poderá se inscrever em somente um curso (para que mais alunos tenham a oportunidade de fazer um curso);
• O mesmo aluno poderá se inscrever várias vezes no mesmo curso, porém apenas contará uma vez (alguns alunos são ansiosos e se cadastram várias vezes para garantir que se inscreveram).

A entrada é uma lista contendo todos os cursos e todos os alunos que se inscreveram em cada curso. Alunos que se cadastraram várias vezes no mesmo curso continuam inscritos naquele curso, porém só contam uma vez. Porém, alunos que se cadastraram em mais de um curso serão excluídos de todos os cursos.

## Entrada
A primeira linha de entrada conterá um inteiro n (1 ≤ n ≤ 105): a quantidade de cursos disponíveis para inscrição. As próximas linhas descreverão informações para cada curso i ∈ [1, . . . , n]. Primeiramente, será fornecida a quantidade de alunos ki cadastrados nesse curso (1 ≤ ki ≤ 105 ). As próximas ki linhas terão apenas um número tij (1 ≤ tij ≤ 106), o código escolar do aluno inscrito. É garantido que a entrada terá no máximo 2 * 10^5 alunos.

## Saída 
Uma única linha contendo n números: a quantidade de alunos de fato inscritos em cada curso após a verificação, na mesma ordem em que os cursos aparecem na entrada.