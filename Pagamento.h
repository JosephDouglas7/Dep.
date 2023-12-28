//Feito com a ajuda do chat GPT
#include <stdio.h>
#include<string.h> 

// Definindo o tipo abstrato de dados Pagamento 
typedef struct {
    float valor; // Valor do pagamento
    char forma[50]; // Forma de pagamento
}Pagamentos;

// Função para inicializar o pagamento
void inicializapagamento1(Pagamentos *pagamento1, float valor, const char*forma) {
    pagamento1->valor = valor;
    strncpy(pagamento1->forma, forma, sizeof(pagamento1->forma));
}

// Função para imprimir o pagamento
void imprimepagamento(Pagamentos *pagamento1) {
    printf("Pagamento: R$ %.2f via %s\n", pagamento1->valor, pagamento1->forma);
}

int pagamento1(){
    Pagamentos meu_pagamento;
    inicializapagamento1(&meu_pagamento, 150.00, "Cartão de Crédito");
    imprimepagamento(&meu_pagamento); 
    return 0;
}

int pagamento2() {
    pagamento1();
    return 0;
}
