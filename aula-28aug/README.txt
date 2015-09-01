* DESCRIÇÃO
Este exercício consiste na implementação da estrutura de dados TAD vetor_t que
armazena cartas de um baralho.

O exercício consiste em terminar de implementar as funções descritas no 
arquivo vetor.c, que é utilizado em principal.c. O principal.c
testa as funções da TAD vetor inserindo ou removendo cartas.
Portanto, MODIFIQUE o vetor.c e NÃO altere principal.c.
O que deve ser alterado:
- vetor.c
O que não deve ser alterado:
- o resto.

Todos os arquivos do trabalho estão no GitHub pasta do dia da aula:
git clone https://github.com/joao-lima/elc1066-2015-2

As funções são:
vetor_t* vetor_cria(void);
void vetor_destroi(vetor_t* vet);
int vetor_numelem(vetor_t *vet);
void vetor_insere_carta(vetor_t *vet, int indice, carta c);
carta vetor_remove_carta(vetor_t *vet, int indice);
carta vetor_acessa_carta(vetor_t *vet, int indice);

A compilação do trabalho envolve diversos arquivos. Quem utiliza Codeblocks,
adicione ao projeto todos os arquivos. Quem utilizar um sistema Linux pode
compilar com o programa make digitando:
make

Ou na linha de comando manualmente com:
gcc -Wall -g -o principal memo.c carta.c vetor.c principal.c -lm

IMPORTANTE:
O vetor deverá utilizar alocação dinâmica por meio das funções fornecidas em
memo.h que são:
void* memo_aloca( size_t tam );
void* memo_realoca( void* ptr, size_t tam );
void memo_libera( void* ptr );

Utilize as funções da mesma forma como com malloc e free. Ao final do programa
utilize a função:
void memo_relatorio( void );

Como no arquivo principal.c, para imprimir o número de alocações e liberações
efetuadas pelo programa.

