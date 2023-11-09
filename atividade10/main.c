#include <stdio.h>
#include "tabela_hash.h"

int main() {
 
  tabela_hash* tabela = tabela_hash_criar(10);

 
  tabela_hash_put(tabela, "chave1", "valor1");
  tabela_hash_put(tabela, "chave2", "valor2");
  tabela_hash_put(tabela, "chave3", "valor3");

  
  char* valor = tabela_hash_get(tabela, "chave1");
  printf("Valor associado à chave 'chave1': %s\n", valor);

 
  int existe = tabela_hash_contains(tabela, "chave2");
  printf("A chave 'chave2' existe? %d\n", existe);

  
  tabela_hash_remove(tabela, "chave2");

  
  existe = tabela_hash_contains(tabela, "chave2");
  printf("A chave 'chave2' existe? %d\n", existe);

  tabela_hash_liberar(tabela);

  return 0;
}