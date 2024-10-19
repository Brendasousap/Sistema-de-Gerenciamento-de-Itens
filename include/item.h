#ifndef ITEM_H
#define ITEM_H

// Definição da estrutura Item
typedef struct {
    int id;
    char nome[30];
} Item;

// Declarações das funções
void cadastrarItem();
void listarItens();
void editarItem();
void excluirItem();
void buscarItem();
void ordenarItens();
void quickSort(Item arr[], int low, int high);
int partition(Item arr[], int low, int high);

#endif