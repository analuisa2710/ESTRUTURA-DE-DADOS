#include <stdio.h>
#include "lista.h"
#include <locale.h>
#include <time.h>

int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");

    No* lista_nao_ordenada = NULL;
    No* lista_ordenada = NULL;

    FILE* arquivo = fopen("1kk_rand_float.csv", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    float numero;
    while (fscanf(arquivo, "%f", &numero) == 1) {
     
        lista_inserir_no(&lista_nao_ordenada, numero);

        
        lista_inserir_no_ordenado(&lista_ordenada, numero);
    }

    fclose(arquivo);

    int num_insercoes = 1000000;
    clock_t inicio_nao_ordenada, fim_nao_ordenada;
    double tempo_nao_ordenada = 0.0;

    inicio_nao_ordenada = clock();
    for (int i = 0; i < num_insercoes; i++) {
        lista_inserir_no(&lista_nao_ordenada, 0.0);
    }
    fim_nao_ordenada = clock();
    tempo_nao_ordenada = (double)(fim_nao_ordenada - inicio_nao_ordenada) / CLOCKS_PER_SEC;

    clock_t inicio_ordenada, fim_ordenada;
    double tempo_ordenada = 0.0;

    inicio_ordenada = clock();
    for (int i = 0; i < num_insercoes; i++) {
        lista_inserir_no_ordenado(&lista_ordenada, 0.0);
    }
    fim_ordenada = clock();
    tempo_ordenada = (double)(fim_ordenada - inicio_ordenada) / CLOCKS_PER_SEC;


    printf("Tempo médio de inserção na Lista Não Ordenada: %f segundos\n", tempo_nao_ordenada / num_insercoes);
    printf("Tempo médio de inserção na Lista Ordenada: %f segundos\n", tempo_ordenada / num_insercoes);

    printf("Tempo total de execução para Lista Não Ordenada: %f segundos\n", tempo_nao_ordenada);
    printf("Tempo total de execução para Lista Ordenada: %f segundos\n", tempo_ordenada);

    return 0;
}