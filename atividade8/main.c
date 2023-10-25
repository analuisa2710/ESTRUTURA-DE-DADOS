#include <stdio.h>
#include "lista.h"

int main() {
    No* minha_lista = criar_lista();

    lista_inserir_inicio(minha_lista, 'A');
    lista_inserir_inicio(minha_lista, 'B');
    lista_inserir_inicio(minha_lista, 'A');
    lista_inserir_inicio(minha_lista, 'C');

    printf("Existência de 'B' na lista: %d\n", lista_verificar_existencia(minha_lista, 'B'));
    printf("Existência de 'D' na lista: %d\n", lista_verificar_existencia(minha_lista, 'D'));
    printf("Ocorrências de 'A' na lista: %d\n", lista_verificar_ocorrencias(minha_lista, 'A'));
    
    printf("Lista original: ");
    lista_imprimir_inversa(minha_lista);

    lista_inserir_no_i(minha_lista, 1, 'D');
    printf("Inserido 'D' na posição 1: ");
    lista_imprimir_inversa(minha_lista);

    lista_remover_no_i(minha_lista, 2);
    printf("Removida posição 2: ");
    lista_imprimir_inversa(minha_lista);

    lista_remover_no(minha_lista, 'A');
    printf("Removido 'A': ");
    lista_imprimir_inversa(minha_lista);

    return 0;
}