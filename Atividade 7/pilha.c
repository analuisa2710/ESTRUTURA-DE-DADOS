#include <stdlib.h>
#include <string.h>
#include "pilha.h"

struct Pilha {
    int topo;
    char* dados[100];
};

Pilha* cria_pilha() {
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    p->topo = 0;
    return p;
}

void push(Pilha* p, char* v) {
    p->dados[p->topo] = strdup(v);
    (p->topo)++;
}

char* pop(Pilha* p) {
    (p->topo)--;
    return p->dados[p->topo];
}

void libera_pilha(Pilha* p) {
    for(int i = 0; i < p->topo; i++) {
        free(p->dados[i]);
    }
    free(p);
}