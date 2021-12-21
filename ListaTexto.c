#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ListaTexto.h"

ListaTexto * cria_lista() {
  ListaTexto *l = malloc(sizeof(ListaTexto));

  if (l == NULL) {
    return NULL;
  }

  l->quantidade = 0;

  return l;
}

void destroi_lista(ListaTexto *l) {
  free(l);
}

// adiciona ao final da lista
int adicionar_lista(ListaTexto *l, char *texto) {
  // se não existe mais espaço dentro do vetor
  if (l->quantidade == MAX) {
    return -1;
  }

  // NÃO funciona para copiar uma string para outra!
  // só estou armazenando a referência de uma string que já exista.
  l->v[l->quantidade] = texto; 
  l->quantidade++;

  return 0;
}

// insere em alguma posição da lista
int inserir_lista(ListaTexto *l, int posicao, char *texto) {
  // testar se a posição é válida e se tem espaço
  // inserir no meio da lista
  // retorna -1 se não for possível inserir na lista ou 0 se tudo for ok

  // [ A R F ] // inserir(1, T)
  // [ A T R F ] // inserir(3, W)
  // [ A T R W F ] // inserir(3, W)
  // [ A T R W F ] // inserir(5 pra frente, U)
  // [ A T R W F U ] // inserir(-1, E)
  // ERRO [ A T R W F U ]

  return -1;
}

// retornar o elemento na posição 'posicao'
char * acessar_lista(ListaTexto *l, int posicao) {
  if (posicao < 0 || posicao >= l->quantidade) {
    return NULL;
  }

  return l->v[posicao];
}

int strings_iguais(char *s1, char *s2) {
  int i;

  int tam1 = strlen(s1);
  int tam2 = strlen(s2);

  if (tam1 != tam2) {
    return FALSE;
  }

  for (i = 0; i < tam1; i++) {
    if (toupper(s1[i]) != toupper(s2[i])) {
      return FALSE;
    }
  }

  return TRUE;
}

// retornar o índice do texto buscado ou -1 caso não encontre
int buscar_lista(ListaTexto *l, char *buscado) {
  int i = 0;

  // para cada posição da lista...
  for (i = 0; i < l->quantidade; i++) {
    // ...verifica se cada string é igual à string buscada
    if (strings_iguais(l->v[i], buscado)) {
      return i;
    }
  }

  return -1;
}

// remove um elemento da lista e retorna ele ou NULL caso a posição não exista na lista
char * remover_lista(ListaTexto *l, int posicao) {
  int i;
  char * removido;

  // se posição não existe, retorne NULL
  if (posicao < 0 || posicao >= l->quantidade) {
    return NULL;
  }

  removido = l->v[posicao];
  // quero excluir a posição. então vou copiar por cima dela a posicao+1, depois a posicao+2 no lugar da posicao+1, e por aí vai..
  for (i = posicao; i < l->quantidade-1; i++) {
    l->v[i] = l->v[i+1];
  }

  l->quantidade--;

  return removido;
}

// imprime a lista para que possamos verificar o seu estado atual
void imprimir_lista(ListaTexto *l) {
  int i;

  printf("[");
  for (i = 0; i < l->quantidade; i++) {
    printf(" (%s) ", l->v[i]);
  }
  printf("]\n");
}