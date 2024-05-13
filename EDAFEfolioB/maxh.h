/*
** file: maxh.h
**
** max Heap (binary tree on array)
** UC: 21046 - EDAF @ UAb
** e-f�lio B 2023-24
**
** Aluno: 1901337 - Miguel Gon�alves
*/

// Defina:
//   Em maxh.h as classes da estrutura de dados
//   Em maxh.cpp a implementa��o dos m�todos das classes da estrutura de dados
// N�o altere o nome das classes nem dos atributos obrigat�rios!

// definir int max heap em array

#ifndef IMAXH_H
#define IMAXH_H

class IMAXH {
private:
    int* v;     // vetor com n�s
    int n;      // num. n�s usados (dimens�o atual do vetor)
    int nv;     // dim max do vetor (capacidade)

    void swap(int& a, int& b); // Fun��o auxiliar para troca de elementos ( para nao usar o std::swap do <algorithm>, apesar de ser a mesma coisa )
public:
    IMAXH(int nmax = 15);    // cria heap vazio c/ capacidade nmax n�s (15 por defeito)
    ~IMAXH();

    //  insert: Comando que insere itens no final do heap pela ordem apresentada
    //  @param item: integer node para adicionar ao heap
    void insert(int item);
    //  print: Comando que faz o heapify da lista e imprime". 
    void print();
    //  print_max: Comando que imprime o numero maximo do heap
    void print_max();
    // dim: Comando que imprime a dimensao atual do heap
    void dim();
    // dim_max: Comando que imprime a dimens�o maxima do heap
    void dim_max();
    // clear: Comando que esvazia o heap
    void clear();
    // heapify_up : Comando que corre o algoritmo heapify up no vetor items
    // @param items: o vetor de items a ser heapified
    // @param numItems: total dos items para facilitar o uso do algoritmo    
    void heapify_up(int* items, int numItems);
    // heapify_top_down : algoritmo heapify top down 
    // @param items: o vetor de items a ser heapified
    // @param numItems: total dos items para facilitar o uso do algoritmo    
    void heapify_top_down(int* items, int numItems);
    // heapify_down : algoritmo heapify down 
    // @param index: o index em que come�a o heapify, inicialmente ser� o primeiro (maior) e usando recurs�o vai descendo a arvore
    void heapify_bottom_up(int index);
    // remove_max: Comando para remover o maior valor do heap
    void remove_max();
    // redim_max: Comando para redimensionar o tamanho maximo do heap
    void redim_max(int N);
    // get_max: Funcao auxiliar para obter o tamanho maximo do heap
    int get_max();
    // get_current_size: Funcao auxiliar para obter o tamanho atual do heap
    int get_current_size();

};

#endif // IMAXH_H

