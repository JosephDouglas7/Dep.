//Feito com a ajuda do chat GPT
#include <stdio.h>

// Definindo o tipo abstrato de dados Data
typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

// Função para inicializar a data
void inicializaData(Data *data, int dia, int mes, int ano) {
    data->dia = dia;
    data->mes = mes;
    data->ano = ano;
}

// Função para imprimir a data
void imprimeData(Data *data) {
    printf("Data de Nascimento: %02d/%02d/%04d\n", data->dia, data->mes, data->ano);
}

int data() {
    Data minha_data;
    inicializaData(&minha_data, 15, 10, 2023);
    imprimeData(&minha_data);
    return 0;
}
