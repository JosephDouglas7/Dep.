//Esse codigo pode ser aproveitado para linguagem python, linguagem C++
//feito com a ajuda do ChatGPT
#include <stdio.h>

int validar_pagamento(float valor) {
    if (valor > 0) {
        return 1;
    } else {
        return 0;
    }
}

int pagamento0() {
    float valor;
    printf("Digite o valor do pagamento: ");
    scanf("%f", &valor);

    if (validar_pagamento(valor)) {
        printf("Pagamento válido.\n");
    } else {
        printf("Pagamento inválido.\n");
    }

    return 0;
}
