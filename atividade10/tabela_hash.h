#ifndef TABELA_HASH_H
#define TABELA_HASH_H

#include <stdbool.h>


typedef struct {
  char** dados;
  int tamanho;
  int quantidade;
} tabela_hash;


tabela_hash* tabela_hash_criar(int tamanho);


void tabela_hash_liberar(tabela_hash* tabela);


char* tabela_hash_get(tabela_hash* tabela, char* chave);

void tabela_hash_put(tabela_hash* tabela, char* chave, char* dado);


int tabela_hash_contains(tabela_hash* tabela, char* chave);


void tabela_hash_remove(tabela_hash* tabela, char* chave);


int hash(char* chave);

#endif