#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

typedef struct No {
    char valor;
    struct No* proximo;
} No;

No* criar_lista() {
    No* cabeca = (No*)malloc(sizeof(No));
    cabeca->proximo = NULL;
    return cabeca;
}

void lista_inserir_inicio(No* cabeca, char valor) {
    No* novo_no = (No*)malloc(sizeof(No));
    novo_no->valor = valor;
    novo_no->proximo = cabeca->proximo;
    cabeca->proximo = novo_no;
}

int lista_verificar_existencia(No* L, char valor_busca) {
    No* atual = L->proximo;
    while (atual != NULL) {
        if (atual->valor == valor_busca) {
            return 1; // Valor encontrado
        }
        atual = atual->proximo;
    }
    return 0; // Valor não encontrado
}

int lista_verificar_ocorrencias(No* L, char valor_busca) {
    int ocorrencias = 0;
    No* atual = L->proximo;
    while (atual != NULL) {
        if (atual->valor == valor_busca) {
            ocorrencias++;
        }
        atual = atual->proximo;
    }
    return ocorrencias;
}

void lista_imprimir_inversa(No* L) {
    if (L->proximo == NULL) {
        return; // Lista vazia, nada a imprimir
    }
    
    No* atual = L->proximo;
    char valores[100]; // Supomos um limite de 100 nós na lista
    int i = 0;

    while (atual != NULL) {
        valores[i] = atual->valor;
        i++;
        atual = atual->proximo;
    }

    for (int j = i - 1; j >= 0; j--) {
        printf("%c ", valores[j]);
    }
    printf("\n");
}

void lista_inserir_no_i(No* L, int i, char valor) {
    No* novo_no = (No*)malloc(sizeof(No));
    novo_no->valor = valor;
    
    No* atual = L;
    for (int j = 0; j < i; j++) {
        if (atual->proximo == NULL) {
            free(novo_no);
            return; // Não é possível inserir na posição i
        }
        atual = atual->proximo;
    }
    
    novo_no->proximo = atual->proximo;
    atual->proximo = novo_no;
}

void lista_remover_no_i(No* L, int i) {
    No* atual = L;
    for (int j = 0; j < i; j++) {
        if (atual->proximo == NULL) {
            return; // Não há nada para remover na posição i
        }
        atual = atual->proximo;
    }
    
    No* no_remover = atual->proximo;
    if (no_remover != NULL) {
        atual->proximo = no_remover->proximo;
        free(no_remover);
    }
}

void lista_remover_no(No* L, char valor_busca) {
    No* atual = L;
    while (atual->proximo != NULL) {
        if (atual->proximo->valor == valor_busca) {
            No* no_remover = atual->proximo;
            atual->proximo = no_remover->proximo;
            free(no_remover);
        } else {
            atual = atual->proximo;
        }
    }
}