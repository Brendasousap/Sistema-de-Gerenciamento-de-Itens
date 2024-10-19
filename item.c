#include <stdio.h>
#include <string.h>
#include "item.h"

#define MAX_ITENS 100

typedef struct {
    int id;
    char nome[30];
} Item;

Item itens[MAX_ITENS];
int totalItens = 0;

void cadastrarItem() {
    if (totalItens >= MAX_ITENS) {
        printf("Capacidade máxima de itens atingida.\n");
        return;
    }
    
    printf("Digite o ID do item: ");
    scanf("%d", &itens[totalItens].id);
    printf("Digite o nome do item: ");
    scanf("%s", itens[totalItens].nome);
    
    totalItens++;
    printf("Item cadastrado com sucesso!\n");
}

void listarItens() {
    for (int i = 0; i < totalItens; i++) {
        printf("ID: %d, Nome: %s\n", itens[i].id, itens[i].nome);
    }
}

void editarItem() {
    int id, encontrado = -1;
    printf("Digite o ID do item a ser editado: ");
    scanf("%d", &id);
    
    for (int i = 0; i < totalItens; i++) {
        if (itens[i].id == id) {
            encontrado = i;
            break;
        }
    }
    
    if (encontrado != -1) {
        printf("Digite o novo nome: ");
        scanf("%s", itens[encontrado].nome);
        printf("Item editado com sucesso!\n");
    } else {
        printf("Item não encontrado.\n");
    }
}

void excluirItem() {
    int id, encontrado = -1;
    printf("Digite o ID do item a ser excluído: ");
    scanf("%d", &id);
    
    for (int i = 0; i < totalItens; i++) {
        if (itens[i].id == id) {
            encontrado = i;
            break;
        }
    }
    
    if (encontrado != -1) {
        for (int i = encontrado; i < totalItens - 1; i++) {
            itens[i] = itens[i + 1];
        }
        totalItens--;
        printf("Item excluído com sucesso!\n");
    } else {
        printf("Item não encontrado.\n");
    }
}

void buscarItem() {
    int id;
    printf("Digite o ID do item para buscar: ");
    scanf("%d", &id);

    int inicio = 0, fim = totalItens - 1, meio;
    while (inicio <= fim) {
        meio = (inicio + fim) / 2;
        if (itens[meio].id == id) {
            printf("Item encontrado: ID: %d, Nome: %s\n", itens[meio].id, itens[meio].nome);
            return;
        } else if (itens[meio].id < id) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    printf("Item não encontrado.\n");
}

void ordenarItens() {
    quickSort(itens, 0, totalItens - 1);
    printf("Itens ordenados com sucesso!\n");
}

void quickSort(Item arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int partition(Item arr[], int low, int high) {
    int pivot = arr[high].id;
    int i = (low - 1);
    
    for (int j = low; j < high; j++) {
        if (arr[j].id < pivot) {
            i++;
            Item temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    
    Item temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    
    return (i + 1);
}