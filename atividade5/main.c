#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bubble_sort.h"

#define MAX_PALAVRA 100

int main(int argc, char* argv[]){
    if (argc != 2) {
        printf("Uso: %s <arquivo de entrada>\n", argv[0]);
        return 1;
    }

    FILE* arquivo_entrada = fopen(argv[1], "r");
    if (arquivo_entrada == NULL) {
        perror("Erro ao abrir o arquivo de entrada");
        return 1;
    }

    char linha[MAX_PALAVRA];
    char* palavras[MAX_PALAVRA];
    int num_palavras = 0;

    
    while (fgets(linha, sizeof(linha), arquivo_entrada)) {
        linha[strcspn(linha, "\n")] = '\0'; 
        palavras[num_palavras] = strdup(linha);
        num_palavras++;
    }

    fclose(arquivo_entrada);

    
    bubble_sort(palavras, num_palavras);


    FILE* arquivo_saida = fopen("arq_palavras_ordenado.txt", "w");
    if (arquivo_saida == NULL) {
        perror("Erro ao criar o arquivo de saída");
        return 1;
    }

    for (int i = 0; i < num_palavras; i++) {
        fprintf(arquivo_saida, "%s\n", palavras[i]);
        free(palavras[i]); 

    fclose(arquivo_saida);

    printf("Palavras ordenadas foram escritas em 'arq_palavras_ordenado.txt'\n");

    return 0;
}
