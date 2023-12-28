//Esse codigo pode ser aproveitado para linguagem python, linguagem C++
//feito com a ajuda do ChatGPT
#include <stdio.h>
#include <ctype.h>

int validar_nome(char* nome) {
    int i = 0;
    while (nome[i]) {
        if (!isalpha(nome[i]) && nome[i] != ' ') {
            return 0;
        }
        i++;
    }
    return 1;
}

int nome() {
    char nome[100];
    printf("Digite o seu nome: ");
    fgets(nome, 100, stdin);

    if (validar_nome(nome)) {
        printf("Nome válido.\n");
    } else {
        printf("Nome inválido.\n");
    }

    return 0;
}
