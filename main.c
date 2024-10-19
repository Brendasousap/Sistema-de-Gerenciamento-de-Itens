#include <stdio.h>
#include <string.h>
#include "login.h"
#include "item.h"

void menu() {
    printf("\nMenu de Opções:\n");
    printf("1. Cadastrar Item\n");
    printf("2. Listar Itens\n");
    printf("3. Editar Item\n");
    printf("4. Excluir Item\n");
    printf("5. Realizar Busca Binária em Item\n");
    printf("6. Ordenar Itens (QuickSort)\n");
    printf("0. Sair\n");
}

int main() {
    char usuario[30], senha[30], email[80];
    
    if (!login(usuario, senha)) {
        printf("Login falhou!\n");
        return 0;
    }
    
    if (!validarEmail(email)) {
        printf("Email inválido!\n");
        return 0;
    }

    printf("Bem-vindo(a) %s!\n", usuario);
    
    int opcao;
    do {
        menu();
        printf("\nEscolha uma opção: ");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                cadastrarItem();
                break;
            case 2:
                listarItens();
                break;
            case 3:
                editarItem();
                break;
            case 4:
                excluirItem();
                break;
            case 5:
                buscarItem();
                break;
            case 6:
                ordenarItens();
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 0);
    
    return 0;
}
