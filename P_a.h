#include <stdio.h>
#include<string.h>

// Definindo o tipo abstrato de dados Pagamento 
int pagamento();
typedef struct {
    float valor; // Valor do pagamento
    char forma[50]; // Forma de pagamento
} Pagamentos1;

// Definindo o tipo abstrato de dados PagamentosAtuais
typedef struct {
    Pagamentos1 pagamentos[100]; // Lista de pagamentos
    int quantidade; // Quantidade de pagamentos
} PagamentosAtuais;

// Função para inicializar o pagamento
void inicializapagamento(Pagamentos1 *pagamento2, float valor, const char *forma) {
    pagamento2->valor = valor;
    strncpy(pagamento2->forma, forma, sizeof(pagamento2->forma));
}

// Função para inicializar os pagamentos atuais
void inicializaPagamentosAtuais(PagamentosAtuais *pagamentosAtuais) {
    pagamentosAtuais->quantidade = 0;
}

// Função para adicionar um pagamento aos pagamentos atuais
void adicionaPagamento(PagamentosAtuais *pagamentosAtuais, Pagamentos1 pagamento2) {
    if (pagamentosAtuais->quantidade < 100) {
        pagamentosAtuais->pagamentos[pagamentosAtuais->quantidade] = pagamento2;
        pagamentosAtuais->quantidade++;
    } else {
        printf("Erro: Não é possível adicionar mais pagamentos.\n");
    }
}

// Função para imprimir os pagamentos atuais
void imprimePagamentosAtuais(PagamentosAtuais *pagamentosAtuais) {
    printf("Pagamentos Atuais:\n");
    for (int i = 0; i < pagamentosAtuais->quantidade; i++) {
        printf("Pagamento %d: R$ %.2f via %s\n", i + 1, pagamentosAtuais->pagamentos[i].valor, pagamentosAtuais->pagamentos[i].forma);
    }
}

int pagamento() {
    Pagamentos1 pagamento1;
    inicializapagamento(&pagamento1, 150.00, "Cartão de Crédito");

    Pagamentos1 pagamento2;
    inicializapagamento(&pagamento2, 200.00, "Boleto Bancário");

    PagamentosAtuais meus_pagamentos;
    inicializaPagamentosAtuais(&meus_pagamentos);

    adicionaPagamento(&meus_pagamentos, pagamento1);
    adicionaPagamento(&meus_pagamentos, pagamento2);

    imprimePagamentosAtuais(&meus_pagamentos);

    return 0;
}
