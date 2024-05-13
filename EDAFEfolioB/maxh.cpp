/*
** file: maxh.cpp
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

#include "maxh.h"
#include <iostream>
#include <cmath>

using namespace std;


void IMAXH::swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

IMAXH::IMAXH(int nmax) {
    nv = nmax;
    n = 0;
    v = new int[nv];
}

IMAXH::~IMAXH() {
    delete[] v;
    v = nullptr;
}

void IMAXH::insert(int item) {
    // Insere o novo item no final do vetor
    v[n] = item;
    n++; // Incrementa o contador de elementos do heap
}

void IMAXH::print() {
    heapify_top_down(v, n); // ordenamos o heap

    // Imprime a �rvore do heap
    cout << "Heap="; // Imprime o cabe�alho da �rvore do heap
    int level = 0; // Inicializa o n�vel atual da �rvore
    int count = 0; // Inicializa o contador de elementos por n�vel
    for (int i = 0; i < n; ++i) {
        // Verifica se � necess�rio mudar de linha para o pr�ximo n�vel da �rvore
        if (i == count) {
            cout << "\n"; // Muda de linha
            count += (int)pow(2, level); // Atualiza o contador de elementos por n�vel
            level++; // Incrementa o n�vel atual da �rvore
        }
        // Imprime o elemento atual do heap
        cout << v[i];
        // Verifica se � o �ltimo elemento do n�vel atual
        if (i != count - 1 && i != n - 1) {
            cout << " "; // Imprime um espa�o se n�o for o �ltimo elemento do n�vel e n�o for o �ltimo elemento do heap
        }
    }
    cout << "\n"; // Imprime uma nova linha no final da �rvore do heap
}

void IMAXH::print_max()
{
    // Ajusta os elementos do heap
    heapify_up(v, n);

    // como o primeiro elemento � sempre o maior apenas temos de imprimir o primeiro elemento do vector
    cout << "Max= " << v[0] << "\n";
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
    delete[] v;
    v = new int[nv];
    n = 0; // Define o n�mero de elementos como zero
}

void IMAXH::remove_max() {
    heapify_top_down(v, n);
    int maxItem = v[0]; // O maior item � o primeiro elemento
    v[0] = v[n - 1]; // Substitui o primeiro elemento pelo �ltimo
    v[n - 1] = '\0';
    n--; // Reduz o tamanho do heap
    heapify_bottom_up(0); // Reorganiza o heap a partir da raiz
}

void IMAXH::heapify_bottom_up(int index) {
    // Inicialmente, assumimos que o n� atual � o maior
    int largest = index;

    // Calcula os �ndices dos filhos esquerdo e direito
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    // Verifica se o filho esquerdo existe e se � maior que o n� atual
    if (left < n && v[left] > v[largest])
        largest = left;

    // Verifica se o filho direito existe e se � maior que o n� atual ou o filho esquerdo
    if (right < n && v[right] > v[largest])
        largest = right;

    // Se o maior elemento n�o for o pr�prio n� atual, faz a troca e continua a heapify_down recursivamente
    if (largest != index) {
        swap(v[index], v[largest]);
        heapify_bottom_up(largest);
    }
}

void IMAXH::heapify_up(int* items, int numItems) {

    // criamos uma lista auxiliar pois os items podem ser um ponteiro para o vector atual do heap
    int* aux = new int[nv];
    for (int j = 0; j < numItems; j++) {
        aux[j] = items[j];
    }
    clear(); // Limpa o heap existente

    // Copiar os elementos do array auxiliar para o heap
    for (int i = 0; i < numItems; ++i) {
        v[i] = aux[i];
    }
    n = numItems;

    // Construimos o heap usando o algoritmo bottom-up
    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify_bottom_up(i);
    }

    delete[] aux; // libertamos o auxiliar
}

void IMAXH::heapify_top_down(int* items, int numItems) {

    // criamos uma lista auxiliar pois os items podem ser um ponteiro para o vector atual do heap 
    int* aux = new int[nv];
    for (int j = 0; j < numItems; j++)
    {
        aux[j] = items[j];
    }
    clear(); // Limpa o heap existente

    // Inserir os elementos do array no heap
    for (int i = 0; i < numItems; ++i) {
        insert(aux[i]);

        // Corrigir o heap chamando heapify_up a partir do �ltimo �ndice inserido
        int index = n - 1;
        while (index > 0 && v[(index - 1) / 2] < v[index]) {
            swap(v[(index - 1) / 2], v[index]);
            index = (index - 1) / 2;
        }
    }
    delete[] aux;
}

void IMAXH::redim_max(int N)
{
    // Liberta a mem�ria alocada para o vetor antigo
    nv = N;
    clear();
}

int IMAXH::get_max() { return nv; }
int IMAXH::get_current_size() { return n; }



// EOF
