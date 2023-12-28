#include<stdio.h> 
#include <string.h> 
#include "util.h"
typedef struct alunos alunos;

typedef struct alunos{ 
 long int matricula; 
 char nome[500]; 
 char nasc[10]; 
 char email[500]; 
 char cpf [11]; 
 char status;
}alunos; 


alunos* preenchealuno(){ 
 alunos*aln; 
 aln = (alunos*)(sizeof(alunos)); 
   printf("informe o nome do estudante:");
   scanf("%ld",&aln->matricula);
   printf("informe o CPF do aluno:"); 
   scanf("%40[^\n]",aln->cpf);
   printf("informe a data de nascimento do aluno:");  
   scanf("%40[^\n]",aln->nasc);
   printf("informe o email do aluno:");  
   scanf("%40[^\n]",aln->email); 
   aln -> status = 'm'; 
   return aln;
} 
char exibealuno(const alunos*al){ 
  char situacao[20]; 
  printf("\n= = = Aluno Cadastrado = = =\n");
  printf("Aluno: %ld\n", al->matricula);
  printf("CPF: %ld\n", al->matricula); 
  printf("Data de nascimento: %ld\n", al->matricula); 
  printf("Email: %ld\n", al->matricula); 
  printf("Situação do aluno: %s\n", situacao);
  return 0;
} 
int menuprincipal(void){ 
  int op;
   printf("\nMenu Principal\n");
   printf("1 - Cadastrar aluno\n");
   printf("2 - Pesquisar aluno\n");
   printf("3 - Exibir aluno\n");
   printf("0 - Encerrar programa\n");
   printf("Escolha sua opção: ");
   scanf("%d", &op);
  return op;
}


