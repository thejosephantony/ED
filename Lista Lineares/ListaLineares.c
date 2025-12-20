/*Lista Lineares


Caracteristicas de uma lista: 1) coleção de dados;  2) elementos do mesmo tipo; 3) itens dispostos em sequência; 4) podem ser contados e ordenados.


1. Linearidade;

2. Homogeneidade (mesmo tipo)

3. Estrutura abstrada, com operações de:
        1. Inserção
        2. Remoção
        3. Busca
        4. Acesso
        5. Percorrimento

obs: pode ser vazia



LISTA SEQUENCIAL: é quando os elementos são armazenados em posições consecutivas da memória

LISTA ENCADEADA: quando em cada nó há um ponteiro que encandeia linearmente todos os itens da lista.
                 É dinâmica se for implementada por uma variável dinâmica.

    1) Simplesmente encadeada: se em cada nó houver um ponteiro apontando para o próximo nó;
    2) Duplcamente encadeada: se em cada nó houver um ponteiro apontado para o nó anterior e o próximo nó;



Como efetuar remoção?
        1) Lista linear sequencial: Localizar o elemento -> removê-lo -> preservar a ordenação ao reogarnizar os elemtentos
        2) Lista Linear Sequencial (chave, posição): acessa direto pela chave -> remove marcando como NULL -> as posições ficam fixas

Qual o custo da remoção?
        1) O(n)  - pior caso
        2) O(1)  - constante

Como efetuar uma consulta (dada a chave de busca)?
        1) Por meio da propria ordem da lista, percorre a lista até encontrar o elemento
        2) acessa diretamente, retornando o dado naquela posicao

Qual o custo da consulta (dada a chave de busca)?
        1) O(n) - pior caso; O(1) - melhor caso (primeiro elemento);  O(n/2) - caso medio;
        2) O(1)

Como efetuar a consulta total ordenada pela chave?
        1) Percorrendo a lista inteira
        2) Percorre todas as posições

Qual o custo da consulta total ordenada pela chave?
        1) O(n)
        2) O(k), em que k é o num de posições

 Oque significa alocac¸˜ ao sequencial de mem´ oria para um conjunto de elementos?
        significa que os elementos ocupam em posições consecutivas na memória.

Oque significa alocac¸˜ ao est´ atica de mem´ oria para um conjunto de elementos?

        A quantidade de memória é definida em tempo de compilação e não pode ser alterada durante a execução do programa.
Qual a diferenc¸a entre alocac¸˜ ao seq¨uencial e alocac¸˜ ao encadeada?
    alocação sequencial os elementos ocupam posições consecutivas na memória, enquanto que alocação encadeada os elementos podem estar em quaisquer posições e são ligados entre si por ponteiros.

     Quais as vantagens de se utilizar alocac¸˜ ao encadeada para um conjunto de elementos? Quais as poss´ ıveis desvantagens?

     Vantagens: inserção e remoção eficientes e não exige memória contígua.
     Desvantagens: maior uso de memória devido aos ponteiros e acesso mais lento aos elementos.

     Qual a diferenc¸a entre alocac¸˜ ao est´ atica e alocac¸˜ ao dinˆ amica?
     estática: tamanho da memória fixo;
     dinâmica: tamanho da memória variável





*/
