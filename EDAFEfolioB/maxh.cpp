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

    // Imprime a árvore do heap
    cout << "Heap="; // Imprime o cabeçalho da árvore do heap
    int level = 0; // Inicializa o nível atual da árvore
    int count = 0; // Inicializa o contador de elementos por nível
    for (int i = 0; i < n; ++i) {
        // Verifica se é necessário mudar de linha para o próximo nível da árvore
        if (i == count) {
            cout << "\n"; // Muda de linha
            count += (int)pow(2, level); // Atualiza o contador de elementos por nível
            level++; // Incrementa o nível atual da árvore
        }
        // Imprime o elemento atual do heap
        cout << v[i];
        // Verifica se é o último elemento do nível atual
        if (i != count - 1 && i != n - 1) {
            cout << " "; // Imprime um espaço se não for o último elemento do nível e não for o último elemento do heap
        }
    }
    cout << "\n"; // Imprime uma nova linha no final da árvore do heap
}

void IMAXH::print_max()
{
    // Ajusta os elementos do heap
    heapify_up(v, n);

    // como o primeiro elemento é sempre o maior apenas temos de imprimir o primeiro elemento do vector
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
    n = 0; // Define o número de elementos como zero
}

void IMAXH::remove_max() {
    heapify_top_down(v, n);
    int maxItem = v[0]; // O maior item é o primeiro elemento
    v[0] = v[n - 1]; // Substitui o primeiro elemento pelo último
    v[n - 1] = '\0';
    n--; // Reduz o tamanho do heap
    heapify_bottom_up(0); // Reorganiza o heap a partir da raiz
}

void IMAXH::heapify_bottom_up(int index) {
    // Inicialmente, assumimos que o nó atual é o maior
    int largest = index;

    // Calcula os índices dos filhos esquerdo e direito
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    // Verifica se o filho esquerdo existe e se é maior que o nó atual
    if (left < n && v[left] > v[largest])
        largest = left;

    // Verifica se o filho direito existe e se é maior que o nó atual ou o filho esquerdo
    if (right < n && v[right] > v[largest])
        largest = right;

    // Se o maior elemento não for o próprio nó atual, faz a troca e continua a heapify_down recursivamente
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

        // Corrigir o heap chamando heapify_up a partir do último índice inserido
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
    // Liberta a memória alocada para o vetor antigo
    nv = N;
    clear();
}

int IMAXH::get_max() { return nv; }
int IMAXH::get_current_size() { return n; }



// EOF
