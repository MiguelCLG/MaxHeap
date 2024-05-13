/*
** file: main-maxh.cpp
**
** max Heap (binary tree on array)
** UC: 21046 - EDAF @ UAb
** e-fólio B 2023-24
**
** Aluno: 1901337 - Miguel Gonçalves
*/

// Defina neste ficheiro:
//   A entrada/saída de dados
//   As instâncias da classe da estrutura de dados
//   A implementação dos comandos através dos métodos da classe
//   Código auxiliar
//   Não utilize variáveis globais!

#include <iostream>
#include <sstream>
#include "maxh.h"
using namespace std;

constexpr int hashFunction(const char* str, int hash = 0) {
    return *str == '\0' ? hash : hashFunction(str + 1, hash + static_cast<int>(*str));
}

// Enum para definir o codigo de cada comando
enum CommandHash {
    INSERT = hashFunction("insert"),
    PRINT_MAX = hashFunction("print_max"),
    PRINT = hashFunction("print"),
    DIM = hashFunction("dim"),
    DIM_MAX = hashFunction("dim_max"),
    CLEAR = hashFunction("clear"),
    DELETE = hashFunction("delete"),
    HEAPIFY_UP = hashFunction("heapify_up"),
    REDIM_MAX = hashFunction("redim_max")
};

// Funcao que recebe o input e define o que vai fazer
void parseCommand(const string& input, IMAXH* heap) {
    istringstream iss(input);
    string cmd;
    int item;
    iss >> cmd;

    // Criei a hashFunction para poder usar o switch case, visto que em c++ apenas integers, chars e enums sao aceites.
    // Fiz desta maneira para o codigo ficar mais legivel.
    switch (hashFunction(cmd.c_str())) {
    case INSERT:
        while (iss >> item) // enquanto houver argumentos na linha, vai inserir no heap
        {
            if (heap->get_current_size() >= heap->get_max()) // verifica se o heap esta cheio
            {
                cout << "Comando insert: Heap cheio!\n"; // Se estiver cheio, imprime uma mensagem
                break;
            }
            heap->insert(item);
        }
        break;
    case PRINT_MAX:
        if (heap->get_current_size() <= 0) { // verifica se o heap esta vazio
            cout << "Comando print_max: Heap vazio!\n";
            break;
        }
        heap->print_max(); // imprime o maior valor do heap
        break;
    case PRINT:
        if (heap->get_current_size() <= 0) { // verifica se o heap esta vazio
            cout << "Comando print: Heap vazio!\n"; // Se estiver vazio, imprime uma mensagem e retorna
            break;
        }
        heap->print(); // imprime o heap
        break;
    case DIM:
        heap->dim(); // imprime a dimensao do heap
        break;
    case DIM_MAX:
        heap->dim_max(); // imprime o numero de elementos maximo que o heap pode ter
        break;
    case CLEAR:
        if (heap->get_current_size() <= 0) { // verifica se o heap esta vazio
            cout << "Comando clear: Heap vazio!\n";
            break;
        }
        heap->clear(); // remove os elementos do heap
        break;
    case DELETE:
        if (heap->get_current_size() <= 0) { // verifica se o heap esta vazio
            cout << "Comando delete: Heap vazio!\n";
            break;
        }
        heap->remove_max(); // remove o valor maximo do heap
        break;
    case HEAPIFY_UP:
    {
        //criamos um auxiliar para o novo heap antes de fazer o heapify
        int* items = new int[heap->get_max()]; // Alocar a memoria para o numero maximo do heap
        int nItems = 0;
        while (iss >> item && nItems < heap->get_max())
        {
            items[nItems] = item;
            nItems++;
        }
        heap->heapify_up(items, nItems); // corremos o heapify_up com o algoritmo bottom_up
        delete[] items; // elimina o vector de items para nao termos memory leaks
        break;
    }
    case REDIM_MAX:
        iss >> item;
        heap->redim_max(item); // redimensiona o tamanho maximo do heap
        break;
    default: // ignora tudo o que nao for um comando (exemplo: # teste 00)
        break;
    }
}



int main() {
    string line; // variavel que guarda o comando
    IMAXH* maxheap = new IMAXH();   // criamos uma instancia do heap

    // Loop enquanto houver linhas no ficheiro, usando o std::getline para ir 
    // buscar a linha de input e introduzi-la na variavel line
    while (getline(cin, line)) {

        // Analisa o comando
        parseCommand(line, maxheap);
    }

    return 0;
}

// EOF
