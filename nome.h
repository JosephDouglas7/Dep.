//Feito com base em: https://github.com/flgorgonio/linguasolta_2020.2/blob/main/aluno.h
typedef struct nome Nome;

struct nome {
  char nome[51];
  char nasc[11];
  char celular[12];
  int status;
};

void moduloAluno(void);
char menuAluno(void);

void* cadastrarAluno(void);
char* telaPesquisarAluno(void);
char* telaAtualizarAluno(void);
char* telaExcluirAluno(void);
void telaErroArquivo(void);


void pesquisarAluno(void);
void atualizarAluno(void);
void excluirAluno(void);
void gravarAluno(Nome*);
void exibirAluno(Nome*);

Nome* buscarAluno(char*);
void exibirAluno(Nome*);
void regravarAluno(Nome*);
