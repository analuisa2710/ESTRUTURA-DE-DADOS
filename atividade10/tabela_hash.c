#include <stdlib.h>
#include "tabela_hash.h"


tabela_hash* tabela_hash_criar(int tamanho) {
  tabela_hash* tabela = malloc(sizeof(tabela_hash));
  tabela->dados = malloc(sizeof(char*) * tamanho);
  tabela->tamanho = tamanho;
  tabela->quantidade = 0;
  return tabela;
}


void tabela_hash_liberar(tabela_hash* tabela) {
  free(tabela->dados);
  free(tabela);
}


char* tabela_hash_get(tabela_hash* tabela, char* chave) {
  int indice = hash(chave);
  return tabela->dados[indice];
}


void tabela_hash_put(tabela_hash* tabela, char* chave, char* dado) {
  int indice = hash(chave);
  tabela->dados[indice] = dado;
}


int tabela_hash_contains(tabela_hash* tabela, char* chave) {
  int indice = hash(chave);
  return tabela->dados[indice] != NULL;
}


void tabela_hash_remove(tabela_hash* tabela, char* chave) {
  int indice = hash(chave);
  tabela->dados[indice] = NULL;
}

int hash(char* chave) {

  return 0;
}