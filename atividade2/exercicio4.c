#include <stdio.h>

int conta_int_array(int array[], int tamanho, int busca) {
    int contador = 0;

    for (int i = 0; i < tamanho; i++) {
        if (array[i] == busca) {
            contador++;
        }
    }

    return contador;
}

int main() {
 
    int meuArray[] = {5, 7, 9, 6, 7, 11, 6, 5};
    int tamanho = sizeof(meuArray) / sizeof(meuArray[0]);
    int numeroBusca = 7;

    int quantidade = conta_int_array(meuArray, tamanho, numeroBusca);

    printf("O número %d aparece %d vezes no array.\n", numeroBusca, quantidade);

    return 0;
}