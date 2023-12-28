//Feito com a ajuda do chat bing
//Feito com base em https://github.com/flgorgonio/linguasolta_2020.2/blob/main/aluno.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nome.h"
#include "util.h"
#include <time.h>
typedef struct nome Nome; 

typedef struct {
    char nome[50];
    char nasc[11];
    char celular[15];
    int status;
}  nome;

void moduloAluno(void) {
  char opcao;
  do {
    opcao = menuAluno();
    switch(opcao) {
      case '1': 	cadastrarAluno();
            break;
      case '2': 	pesquisarAluno();
            break;
      case '3': 	atualizarAluno();
            break;
      case '4': 	excluirAluno();
            break;
    } 		
  } while (opcao != '0');
}


void cadastrarAluno2(void) {
  struct Nome *aln;

  aln = telaCadastrarAluno();
  gravarAluno(aln);
  free(aln);
}


void pesquisarAluno(void) {
  struct nome* aln;
  char* matr;

  matr = telaPesquisarAluno();
  aln = buscarAluno1(matr);
  exibirAluno(aln);
  free(aln); 
  free(matr);
}


void atualizarAluno(void) { 
  char aluno;
  struct nome* aln;
  char* alunos;

  aluno = telaAtualizarNome();
  aln = buscarAluno1(aluno);
  if (aln == 0) {
      printf("\n\nAluno não encontrado!\n\n");
  } else {
      Nome* novoAln = telaCadastrarAluno(); 
      strcpy(novoAln->nome, aluno); 
      regravarAluno(novoAln); 
      free(novoAln); 
      free(aln); 
  }
  free(aluno);
}



void excluirAluno(void) {
  struct nome* aln;
  char *matr;

  matr = telaExcluirAluno();
  aln = (Nome*) malloc(sizeof(Nome));
  aln = buscarAluno1(matr);
  if (aln == 0) {
      printf("\n\nAluno não encontrado!\n\n");
    } else {
      aln->status = 0;
      regravarAluno(aln);
      free(aln);
  }
  free(matr);
}

char menuAluno(void) {
 char op;

 limpaTela();
 printf("\n");
printf("/////////////////////////////////////////////////////////////////////////////\n");
  printf("///                                                                       ///\n");
  printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
  printf("///           = = = = = = = = =  Menu Aluno = = = = = = = = =             ///\n");
  printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
  printf("///                                                                       ///\n");
  printf("///           1. Cadastrar um novo aluno                                  ///\n");
  printf("///           2. Pesquisar os dados de um aluno                           ///\n");
  printf("///           3. Atualizar o cadastro de um aluno                         ///\n");
  printf("///           4. Excluir um aluno do sistema                              ///\n");
  printf("///           0. Voltar ao menu anterior                                  ///\n");
  printf("///                                                                       ///\n");
  printf("///           Escolha a opção desejada: ");
  scanf("%c", &op);
  getchar();
  printf("///                                                                       ///\n");
  printf("///                                                                       ///\n");
  printf("/////////////////////////////////////////////////////////////////////////////\n");
  printf("\n");
  delay(1);
  return op;
}

void telaErroArquivoAluno(void) {
  limpaTela();
  printf("\n");
  printf("/////////////////////////////////////////////////////////////////////////////\n");
  printf("///                                                                       ///\n");
  printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
  printf("///           = = = = = = =  Ops! Ocorreu em erro = = = = = =             ///\n");
  printf("///           = = =  Não foi possível acessar o arquivo = = =             ///\n");
  printf("///           = = = = com informações sobre os alunos = = = =             ///\n");
  printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
  printf("///           = =  Pedimos desculpas pelos inconvenientes = =             ///\n");
  printf("///           = = =  mas este programa será finalizado! = = =             ///\n");
  printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
  printf("///                                                                       ///\n");
  printf("\n\nTecle ENTER para continuar!\n\n");
  getchar();
  exit(1);
}


int validarNome(char* nome) {
    return strlen(nome) > 0 ? 1 : 0;
}

int validarFone(char* fone) {
    return strlen(fone) > 0 ? 1 : 0;
}

void limpaTela1(void) {
    printf("\033[H\033[J");
}

void delay1(int number_of_seconds) {
    int milli_seconds = 1000 * number_of_seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds);
}

struct nome* cadastrarAluno1(void) {
    Nome *aln;
    aln = (Nome*) malloc(sizeof(Nome));

    limpaTela();
    printf("\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///           = = = = = = = = Cadastrar Aluno = = = = = = = =             ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///                                                                       ///\n");
    do {
        printf("///           Nome completo: ");
        scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", aln->nome);
        getchar();
    } while (!validarNome(aln->nome));
    printf("///           Data de Nascimento (dd/mm/aaaa):  ");
    scanf("%[0-9/]", aln->nasc);
    getchar();
    do {
        printf("///           Celular  (apenas números com DDD): ");
        scanf("%[^\n]", aln->celular);
        getchar();
    } while (!validarFone(aln->celular));
    aln->status = 0;
    printf("///                                                                       ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    delay(1);
    return aln;
}



char* telaPesquisarAluno(void) {
  char *matr;
  Nome *aln; // Adicionado a declaração da variável aln

  matr = (char*) malloc(12*sizeof(char));
  aln = (Nome*) malloc(sizeof(Nome)); // Adicionado a alocação de memória para aln
  limpaTela();
  printf("\n");
  printf("/////////////////////////////////////////////////////////////////////////////\n");
  printf("///                                                                       ///\n");
  printf("///          ===================================================          ///\n");
  printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
  printf("///          = = = =   Escola de Idiomas Língua Solta    = = = =          ///\n");
  printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
  printf("///                                                                       ///\n");
  printf("/////////////////////////////////////////////////////////////////////////////\n");
  printf("///                                                                       ///\n");
  printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
  printf("///           = = = = = = = = Pesquisar Aluno = = = = = = = =             ///\n");
  printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
  printf("///                                                                       ///\n");
  do {
    printf("///           Informe o nome do aluno (apenas letras): ");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", aln->nome);
    getchar();
  } while (!validarNome(aln->nome)); // Adicionado a validação do nome
  printf("///                                                                       ///\n");
  printf("///                                                                       ///\n");
  printf("/////////////////////////////////////////////////////////////////////////////\n");
  printf("\n");
  delay(1);
    return matr;
}



char* telaAtualizarAluno(void) {
  char* matr;
  Nome *aln; // Adicionado a declaração da variável aln

  matr = (char*) malloc(12*sizeof(char));
  aln = (Nome*) malloc(sizeof(Nome)); // Adicionado a alocação de memória para aln
  limpaTela();
  printf("\n");
  printf("/////////////////////////////////////////////////////////////////////////////\n");
  printf("///                                                                       ///\n");
  printf("///          ===================================================          ///\n");
  printf("///                                                                       ///\n");
  printf("/////////////////////////////////////////////////////////////////////////////\n");
  printf("///                                                                       ///\n");
  printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
  printf("///           = = = = = = = = Atualizar Aluno = = = = = = = =             ///\n");
  printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
  printf("///                                                                       ///\n");
  do {
    printf("///Informe o nome do aluno (apenas letras): ");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", aln->nome);
    getchar();
  } while (!validarNome(aln->nome)); // Adicionado a validação do nome
  printf("///                                                                       ///\n");
  printf("///                                                                       ///\n");
  printf("/////////////////////////////////////////////////////////////////////////////\n");
  printf("\n");
  delay(1);
    return matr;
}



void* atualizarAluno1(void) {
  char *matr;
  Nome *aln; 

  matr = (char*) malloc(12*sizeof(char));
  aln = (Nome*) malloc(sizeof(Nome)); 
  limpaTela();
  printf("\n");
  printf("/////////////////////////////////////////////////////////////////////////////\n");
  printf("///                                                                       ///\n");
  printf("///                                                                       ///\n");
  printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
  printf("///           = = = = = = = = Atualizar Aluno = = = = = = = =             ///\n");
  printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
  printf("///                                                                       ///\n");
  do {
    printf("///           Informe o nome do aluno (apenas letras): ");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", aln->nome);
    getchar();
  } while (!validarNome(aln->nome)); // Adicionado a validação do nome
  printf("///                                                                       ///\n");
  printf("///                                                                       ///\n");
  printf("/////////////////////////////////////////////////////////////////////////////\n");
  printf("\n");
  delay(1);
    return matr;
}



void gravarAluno(Nome* aln) {
  FILE* fp;

  fp = fopen("alunos.dat", "ab");
  if (fp == 0) {
    telaErroArquivoAluno();
  }
  fwrite(aln, sizeof(Nome), 1, fp);
  fclose(fp);
}


Nome* buscarAluno(char* nome) {
  FILE* fp;
  Nome* aln;

  aln = (Nome*) malloc(sizeof(Nome));
  fp = fopen("alunos.dat", "rb");
  if (fp == 0) {
    telaErroArquivoAluno();
  }
  while(fread(aln, sizeof(Nome), 1, fp)) {
    if ((strcmp(aln->nome, nome) == 0) && (aln->status == 1)) {
      fclose(fp);
      return aln;
    }
  }
  fclose(fp);
  return 0;
}


void exibirAluno(Nome* aln) {

  if (aln == 0) {
    printf("\n= = = Aluno Inexistente = = =\n");
  } else {
    printf("\n= = = Aluno Cadastrado = = =\n");
    printf("Nome do aluno: %s\n", aln->nome);
    printf("Data de Nasc: %s\n", aln->nasc);
    printf("Celular: %s\n", aln->celular);
    printf("Status: %d\n", aln->status);
  }
  printf("\n\nTecle ENTER para continuar!\n\n");
  getchar();
}


void regravarAluno(Nome* aln) {
  int achou;
  FILE* fp;
  Nome* alnLido;

  alnLido = (Nome*) malloc(sizeof(Nome));
  fp = fopen("alunos.dat", "r+b");
  if (fp == 0) {
    telaErroArquivoAluno();
  }
  // while(!feof(fp)) {
  achou = 0;
  while(fread(alnLido, sizeof(Nome), 1, fp) && !achou) {
    //fread(alnLido, sizeof(Aluno), 1, fp);
    if (strcmp(alnLido->nome, aln->nome) == 0) {
      achou = 1;
      fseek(fp, -1*sizeof(Nome), SEEK_CUR);
          fwrite(aln, sizeof(Nome), 1, fp);
      //break;
    }
  }
  fclose(fp);
  free(alnLido);
}
