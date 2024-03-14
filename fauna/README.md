# Fauna
Em uma ilha existem n lagos, ligados entre si por m trilhas naturais. Cada trilha i (1, . . . , m) liga dois lagos (ui , vi) bidirecionalmente, e possui uma distância di.

Nessa ilha, existe o Tiquinho Soares, um indivíduo da espécie salamandra-de-fogo. Tiquinho possui um comportamento diferente das outras salamandras: ele gosta de visitar todos os lagos presentes na ilha. De tempos em tempos ele inicia uma nova jornada do lago 1 e visita todos os outros lagos andando pelas trilhas presentes na ilha. Tiquinho gosta de novidades, então não repete nenhum lago na viagem. Porém, por ter uma necessidade de permanecer em ambientes úmidos, ele não pode ficar muito tempo nas trilhas.

Assim, ele deve escolhê-las visando minimizar a distância total percorrida. Caso Tiquinho inicie sua jornada no lago 1, qual é a menor soma das distâncias das trilhas escolhidas para visitar todos os outros lagos, sendo que ele pode visitar o mesmo lago apenas uma vez? Caso não seja possível encontrar um caminho, imprime −1.

## Entrada
A primeira linha de entrada possui dois inteiro n e m (1 ≤ n ≤ 20, 1 ≤ m ≤ n*(n−1)2). Cada uma das próximas m linhas possui três inteiros ui, vi e di (1 ≤ ui, vi ≤ n, 1 ≤ di ≤ 108), descrevendo uma trilha conectando os lagos ui e vi com distância di (ui ̸= vi e nenhum par de vértices se repete na entrada).

## Saída
o comprimento total mínimo para um caminho iniciando no lago 1 e visitando todos os lagos exatamente uma vez. Note que ele não precisa voltar ao lago 1 após visitar todos.