#include <stdio.h>
#include <string.h>

int busca_string(char *array[], int tamanho, const char *busca) {
    for (int i = 0; i < tamanho; i++) {
        if (strcmp(array[i], busca) == 0) {
            return 1; 
        }
    }
    
    return 0; 
}

int main() {

    char *meuArray[] = {"texto", "J", "EDA"};
    int tamanho = sizeof(meuArray) / sizeof(meuArray[0]);
    const char *busca = "EDO"; 

    int resultado = busca_string(meuArray, tamanho, busca);

    if (resultado == 1) {
        printf("A string de busca existe no array.\n");
    } else {
        printf("A string de busca NÃO existe no array.\n");
    }

    return 0;
}