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
#include <string>
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
void parseCommand(const std::string& input, IMAXH* heap) {
    std::istringstream iss(input);
    std::string cmd;
    int item, pos, pos1, pos2;
    iss >> cmd;

    // Criei a hashFunction para poder usar o switch case, visto que em c++ apenas integers, chars e enums sao aceites.
    // Fiz desta maneira para o codigo ficar mais legivel.
    switch (hashFunction(cmd.c_str())) {
    case INSERT:
        while (iss >> item) // enquanto houver argumentos na linha, vai inserir no heap
            heap->insert(item);
        break;
    case PRINT_MAX:
        heap->print_max(); // retorna o maior valor do heap (raiz)
        break;
    case PRINT:
        heap->print(); // imprime heap
        break;
    case DIM:
        heap->dim();
        break;
    case DIM_MAX:
        heap->dim_max();
        break;
    case CLEAR:
        heap->clear(); 
        break;
    case DELETE:
        heap->remove_max();
        break;
    case HEAPIFY_UP:
    {
        int* items = new int[heap->get_max()]; // Alocar a memoria para o numero maximo do heap
        int nItems = 0;
        while (iss >> item && nItems < heap->get_max())
        {
            items[nItems] = item;
            nItems++;
        }
        heap->heapify_up(items);
        delete[] items; // elimina o vector de items para nao termos memory leaks
        break;
    }
    case REDIM_MAX:
        heap->redim_max(); 
        break;
    default: // ignora tudo o que n�o for um comando (exemplo: # teste 00)
        break;
    }
}



int main() {
    IMAXH maxheap;   // exemplo
    std::string line; // variavel que guarda o comando

    maxheap;

    // Loop enquanto houver linhas no ficheiro, usando o std::getline para ir 
    // buscar a linha de input e introduzi-la na variavel line
    while (std::getline(std::cin, line)) {

        // Analisa o comando
        parseCommand(line, &maxheap);
    }

    // Exemplo de uso
    /*maxheap.insert(3);
    maxheap.insert(2);
    maxheap.insert(15);
    maxheap.insert(5);
    maxheap.insert(4);
    maxheap.insert(45);

    cout << "Max heap: ";
    maxheap.print();

    cout << "Removendo o maximo: " << maxheap.removeMax() << endl;
    cout << "Max heap apos remocao: ";
    maxheap.print();*/

    return 0;
}

// EOF
