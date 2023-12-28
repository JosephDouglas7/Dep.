//Esse codigo pode ser aproveitado para linguagem python, linguagem C++
//Feito com a ajuda do ChatGPT
#include <stdio.h>

int data2() {
    int dia, mes, ano;
    printf("Digite sua data de nascimento (dd/mm/aaaa): ");
    scanf("%d/%d/%d", &dia, &mes, &ano);

    if (ano < 1900 || ano > 2023) {
        printf("Ano inválido!\n");
        return 1;
    }

    if (mes < 1 || mes > 12) {
        printf("Mês inválido!\n");
        return 1;
    }

    if (dia < 1 || dia > 31) {
        printf("Dia inválido!\n");
        return 1;
    }

    if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia == 31) {
        printf("Dia inválido para o mês especificado!\n");
        return 1;
    }

    if (mes == 2) {
        int bissexto = ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0);
        if (dia > 29 || (dia == 29 && !bissexto)) {
            printf("Dia inválido para fevereiro!\n");
            return 1;
        }
    }

    printf("Data válida!\n");
    return 0;
}
