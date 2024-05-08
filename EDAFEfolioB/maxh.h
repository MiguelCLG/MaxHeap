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

    void swap(int& a, int& b); // Fun��o auxiliar para troca de elementos
public:
    IMAXH(int nmax = 15);    // cria heap vazio c/ capacidade nmax n�s
    ~IMAXH();
    // outros atributos e m�todos (prot�tipos) livres
    void insert(int item);
    void print();
    void print_max();
    void dim();
    void dim_max();
    void clear();
    void heapify_up(int* items);
    void redim_max();
    void remove_max();
    void heapify_down(int index);
    int get_max();
};

#endif // IMAXH_H

