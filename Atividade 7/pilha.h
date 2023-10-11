#ifndef PILHA_H
#define PILHA_H

typedef struct Pilha Pilha;

Pilha* cria_pilha();
void push(Pilha* p, char* v);
char* pop(Pilha* p);
void libera_pilha(Pilha* p);

#endif