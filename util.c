#include "util.h"
#include <stdio.h>
#include <string.h>

int nome1(char *nome) {
  int tam;

  tam = strlen(nome);
  for (int i = 0; i < tam - 1; i++) {
    if (!eh_letra(nome[i])) {
      return 0;
    }
  }
  return 1;
}

int eh_palavra(char c) {
  if (c >= 'A' && c <= 'Z') {
    return 1;
  } else if (c >= 'a' && c <= 'z') {
    return 1;
  } else if (c == ' ' || c == 13) {
    return 1;
  } else {
    return 0;
  }
}

//
// Funções que manipulam datas
//

// Recebe um ano e verifica se o mesmo é bissexto
// Retorna 1 se o ano é bissexto ou 0 caso contrário

int eh_bissexto(int aa) {
  if ((aa % 4 == 0) && (aa % 100 != 0)) {
    return 1;
  } else if (aa % 400 == 0) {
    return 1;
  } else {
    return 0;
  }
}

// Recebe uma data no formato (dd, mm, aaaa) e valida a mesma
// Retorna 1 se a data é válida ou 0 caso contrário

int valida_data(int dd, int mm, int aa) {
  int maiorDia;
  if (aa < 0 || mm < 1 || mm > 12)
    return 0;
  if (mm == 2) {
    if (eh_bissexto(aa))
      maiorDia = 29;
    else
      maiorDia = 28;
  } else if (mm == 4 || mm == 6 || mm == 9 || mm == 11) {
    maiorDia = 30;
  } else
    maiorDia = 31;

  if (dd < 1 || dd > maiorDia)
    return 0;

  return 1;
}
