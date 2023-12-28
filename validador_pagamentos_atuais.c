//Esse codigo pode ser aproveitado para linguagem python, linguagem C++
//feito com a ajuda do ChatGPT
#include <stdio.h>

int atuais() {
    double pagamento;

    printf("Insira o valor do pagamento: ");
    scanf("%lf", &pagamento);

    if (pagamento > 0) {
        printf("O pagamento é valido.\n");
    } else if (pagamento < 0) {
        printf("O pagamento é invalido.\n");
    } else {
        printf("O pagamento é zero.\n");
    }

    return 0;
}
