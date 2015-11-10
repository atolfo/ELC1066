* DESCRIÇÃO
Este exercício consiste na implementação da função **grafo_imprime**,
baseado na implementação de um grafo não-direcionado, sem pesos,
com matriz de adjacencia.
Essa função imprime todos os vértices que são adjacentes a um vértice qualquer
do grafo.

O exercício consiste em 
- implementar a função grafo_imprime() no arquivo grafo.c 

A saida esperada do programa é: 
V 0 -> 1 2 5 6 
V 1 -> 0 
V 2 -> 0 
V 3 -> 4 5 
V 4 -> 3 5 6 
V 5 -> 0 3 4 
V 6 -> 0 4 
V 7 -> 8 
V 8 -> 7 
V 9 -> 10 11 12 
V 10 -> 9 
V 11 -> 9 12 
V 12 -> 9 11 

Todos os arquivos do trabalho estão no GitHub pasta do dia da aula:
git clone https://github.com/joao-lima/elc1066-2015-2

A compilação do trabalho envolve diversos arquivos. Quem utiliza Codeblocks,
adicione ao projeto todos os arquivos. Quem utilizar um sistema Linux pode
compilar com o programa make digitando:
make

Ou na linha de comando manualmente com:
gcc -Wall -g -o principal principal.c memo.c grafo.c  -lm

IMPORTANTE:
- Certifique-se que o programa não imprime mensagens de erro.
