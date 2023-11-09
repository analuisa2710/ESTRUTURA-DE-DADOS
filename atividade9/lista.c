#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

No* no(float valor, No* proximo_no) {
    No* novo_no = (No*)malloc(sizeof(No));
    if (novo_no == NULL) {
        fprintf(stderr, "Erro na alocação de memória.\n");
        exit(1);
    }
    novo_no->valor = valor;
    novo_no->proximo_no = proximo_no;
    return novo_no;
}

void lista_inserir_no(No** L, float valor) {
    No* novo = no(valor, NULL);
    novo->proximo_no = *L;
    *L = novo;
}

void lista_imprimir(No* L) {
    while (L != NULL) {
        printf("%f ", L->valor);
        L = L->proximo_no;
    }
    printf("\n");
}

int lista_quantidade_nos(No* L) {
    int count = 0;
    while (L != NULL) {
        count++;
        L = L->proximo_no;
    }
    return count;
}

No* lista_copiar(No* L) {
    No* copia = NULL;
    No* ultimo = NULL;
    while (L != NULL) {
        if (copia == NULL) {
            copia = no(L->valor, NULL);
            ultimo = copia;
        } else {
            ultimo->proximo_no = no(L->valor, NULL);
            ultimo = ultimo->proximo_no;
        }
        L = L->proximo_no;
    }
    return copia;
}

void lista_concatenar(No** L, No* Lc) {
    if (*L == NULL) {
        *L = Lc;
    } else {
        No* temp = *L;
        while (temp->proximo_no != NULL) {
            temp = temp->proximo_no;
        }
        temp->proximo_no = Lc;
    }
}

void lista_liberar(No** L) {
    while (*L != NULL) {
        No* temp = (*L)->proximo_no;
        free(*L);
        *L = temp;
    }
}

int lista_verificar_existencia(No* L, float valor_busca) {
    while (L != NULL) {
        if (L->valor == valor_busca) {
            return 1;  
        }
        L = L->proximo_no;
    }
    return 0; 
}

int lista_verificar_ocorrencias(No* L, float valor_busca) {
    int contador = 0;
    while (L != NULL) {
        if (L->valor == valor_busca) {
            contador++;
        }
        L = L->proximo_no;
    }
    return contador;
}

void lista_imprimir_inversa(No* L) {
    if (L == NULL) {
        return;
    }
    lista_imprimir_inversa(L->proximo_no);
    printf("%f ", L->valor);
}

void lista_inserir_no_i(No** L, float valor, int i) {
    if (i == 0) {
        No* novo_no = no(valor, *L);
        *L = novo_no;
    } else {
        No* atual = *L;
        int pos = 0;
        while (atual != NULL && pos < i - 1) {
            atual = atual->proximo_no;
            pos++;
        }
        if (atual != NULL) {
            No* novo_no = no(valor, atual->proximo_no);
            atual->proximo_no = novo_no;
        }
    }
}

void lista_remover_no_i(No** L, int i) {
    if (*L == NULL || i < 0) {
        return;
    }
    if (i == 0) {
        No* temp = *L;
        *L = (*L)->proximo_no;
        free(temp);
    } else {
        No* atual = *L;
        int pos = 0;
        while (atual->proximo_no != NULL && pos < i - 1) {
            atual = atual->proximo_no;
            pos++;
        }
        if (atual->proximo_no != NULL) {
            No* temp = atual->proximo_no;
            atual->proximo_no = temp->proximo_no;
            free(temp);
        }
    }
}

void lista_remover_no(No** L, float valor_busca) {
    while (*L != NULL && (*L)->valor == valor_busca) {
        No* temp = *L;
        *L = (*L)->proximo_no;
        free(temp);
    }
    if (*L == NULL) {
        return;
    }

    No* atual = *L;
    while (atual->proximo_no != NULL) {
        if (atual->proximo_no->valor == valor_busca) {
            No* temp = atual->proximo_no;
            atual->proximo_no = temp->proximo_no;
            free(temp);
        } else {
            atual = atual->proximo_no;
        }
    }
}

void lista_inserir_no_ordenado(No** L, float valor) {
    No* novo_no = no(valor, NULL);
    if (*L == NULL || valor < (*L)->valor) {
        novo_no->proximo_no = *L;
        *L = novo_no;
    } else {
        No* atual = *L;
        while (atual->proximo_no != NULL && valor > atual->proximo_no->valor) {
            atual = atual->proximo_no;
        }
        novo_no->proximo_no = atual->proximo_no;
        atual->proximo_no = novo_no;
    }
}