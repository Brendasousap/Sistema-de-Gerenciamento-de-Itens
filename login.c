#include <stdio.h>
#include <string.h>

int login(char usuario[], char senha[]) {
    char userCorreto[] = "admin";
    char senhaCorreta[] = "1234";
    
    do {
        printf("Nome de usuário: ");
        scanf("%s", usuario);
        printf("Senha: ");
        scanf("%s", senha);
        
        if (strcmp(usuario, userCorreto) == 0 && strcmp(senha, senhaCorreta) == 0) {
            return 1; // Login bem-sucedido
        } else {
            printf("Usuário ou senha incorretos. Tente novamente.\n");
        }
    } while (1);
    
    return 0;
}

int validarEmail(char email[]) {
    printf("Digite seu e-mail: ");
    scanf("%s", email);

    if (strchr(email, '@') != NULL && strlen(email) < 80) {
        return 1; // E-mail válido
    }
    return 0; // E-mail inválido
}
