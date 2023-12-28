#include <stdio.h>

// Definindo o tipo abstrato de dados Saldo
typedef struct {
    float valor; // Valor do saldo
} Saldo1;

// Função para inicializar o saldo
void inicializaSaldo(Saldo1 *saldo1, float valor) {
    saldo1->valor = valor;
}
//Feito com a ajuda do Chat bing
void imprimeSaldo(Saldo1 *saldo1) {
    printf("Saldo Atual: R$ %.2f\n", saldo1->valor);
}

int saldo() {
    Saldo1 meu_saldo;
    inicializaSaldo(&meu_saldo, 1000.00);
    imprimeSaldo(&meu_saldo);
    return 0;
}
