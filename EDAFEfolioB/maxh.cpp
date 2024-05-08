/*
** file: maxh.cpp
**
** max Heap (binary tree on array)
** UC: 21046 - EDAF @ UAb
** e-fólio B 2023-24
**
** Aluno: 1901337 - Miguel Gonçalves
*/

// Defina:
//   Em maxh.h as classes da estrutura de dados
//   Em maxh.cpp a implementação dos métodos das classes da estrutura de dados

#include "maxh.h"
#include <iostream>
using namespace std;


IMAXH::IMAXH(int nmax) {
    nv = nmax;
    n = 0;
    v = new int[nv];
}

IMAXH::~IMAXH() {
    delete[] v;
    v = nullptr;
}

void IMAXH::swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void IMAXH::insert(int item) {
    if (n >= nv) {
        cout << "Comando insert: Heap cheio!\n";
        return;
    }

    v[n] = item; // Insere o item na próxima posição disponível
    int index = n; // Índice do novo elemento

    // Corrige a posição do novo elemento enquanto ele for maior que o pai, de maneira ao heap ficar com os valores maiores em cima e os menores em baixo
    while (index > 0 && v[(index - 1) / 2] < v[index]) {
        swap(v[(index - 1) / 2], v[index]);
        index = (index - 1) / 2;
    }

    n++; // Aumenta o contador de elementos
}

void IMAXH::print() {
    if (n <= 0) {
        cout << "Comando print: Heap vazio!\n";
        return;
    }
    cout << "Heap=";
    int level = 0;
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (i == count) {
            cout << endl;
            count += pow(2, level);
            level++;
        }
        cout << v[i] << " ";
    }
    cout << endl;
}

void IMAXH::print_max()
{
    if (n <= 0) {
        cout << "Comando print_max: Heap vazio!\n";
        return;
    }
    // como o primeiro elemento é sempre o maior apenas temos de imprimir o primeiro elemento do vector
    cout << "Max= " << v[0] << endl;
}

void IMAXH::dim()
{
    cout << "Heap tem " << n << " itens\n";
}

void IMAXH::dim_max()
{
    cout << "Heap tem capacidade " << nv << " itens\n";
}

void IMAXH::clear() {
    n = 0; // Define o número de elementos como zero
}

void IMAXH::remove_max() {
    if (n <= 0) {
        cout << "Comando delete: Heap vazio!\n";
        return;
    }

    int maxItem = v[0]; // O maior item é o primeiro elemento
    v[0] = v[n - 1]; // Substitui o primeiro elemento pelo último
    n--; // Reduz o tamanho do heap
    heapify_down(0); // Reorganiza o heap para baixo a partir do índice 0
}

void IMAXH::heapify_down(int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < n && v[left] > v[largest])
        largest = left;

    if (right < n && v[right] > v[largest])
        largest = right;

    if (largest != index) {
        swap(v[index], v[largest]);
        heapify_down(largest);
    }
}

void IMAXH::heapify_up(int* items) // recebe um vetor de items
{
    clear(); // Limpa o heap existente

    // Insere cada item no vetor
    for (int i = 0; items[i] != '\0'; ++i) {
        insert(items[i]);
    }
}

void IMAXH::redim_max()
{
}

int IMAXH::get_max() { return nv; }



// EOF
