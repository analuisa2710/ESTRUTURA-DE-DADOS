#include <stdio.h>

int somaArray(int array[], int tamanho) {
    int soma = 0;

    for (int i = 0; i < tamanho; i++) {
        soma += array[i];
    }

    return soma;
}

int main() {
    
    int meuArray[] = {5, 7, 9, 6};
    int tamanho = sizeof(meuArray) / sizeof(meuArray[0]);

    int resultado = somaArray(meuArray, tamanho);

    printf("A soma dos elementos do array é: %d\n", resultado);

    return 0;
}