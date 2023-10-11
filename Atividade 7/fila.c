#include <stdlib.h>
#include "fila.h"

Fila* cria_fila() {
    Fila* f = (Fila*) malloc(sizeof(Fila));
    f->inicio = f->fim = 0;
    return f;
}

void enfileira(Fila* f, int v) {
    f->dados[f->fim] = v;
    (f->fim)++;
}

int desenfileira(Fila* f) {
    int v = f->dados[f->inicio];
    (f->inicio)++;
    return v;
}

void libera_fila(Fila* f) {
    free(f);
}