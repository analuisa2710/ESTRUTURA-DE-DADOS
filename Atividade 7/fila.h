#ifndef FILA_H
#define FILA_H

typedef struct Fila {
    int inicio, fim;
    int dados[100];
} Fila;

Fila* cria_fila();
void enfileira(Fila* f, int v);
int desenfileira(Fila* f);
void libera_fila(Fila* f);

#endif