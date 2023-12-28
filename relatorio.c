//Feito com a ajuda do Chat bing
#include<stdio.h> 
#include<string.h> 
#include<stdlib.h>
typedef struct {
    char primeiroNome[50];
    char sobrenome[50]; 
    char situacao[50];
} Aluno; 

Aluno* buscarAluno2(char* nome) {
    Aluno* aluno = (Aluno*) malloc(sizeof(Aluno));
    strcpy(aluno->primeiroNome, "João"); 
    strcpy(aluno->situacao, "Ativo");

    if (strcmp(aluno->primeiroNome, nome) == 0) { 
        return aluno;
    }
    free(aluno);
    return 0;
}

void relatorioRepublicaEstudantil(char* nomeAluno) {
    Aluno* aluno;

    aluno = buscarAluno2(nomeAluno);
    if (aluno == 0) {
        printf("Aluno não encontrado.\n");
    } else {
        printf("Nome do Aluno: %s\n", aluno->primeiroNome); 
        printf("Situação da República Estudantil: %s\n", aluno->situacao);
        free(aluno);
    }
}
