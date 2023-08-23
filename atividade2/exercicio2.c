#include <stdio.h>

void menor_maior_array(int array[], int tamanho, int *menor, int *maior) {
    
    if (tamanho == 0) {
        *menor = *maior = 0;
        return;
    }

    *menor = *maior = array[0]; 

    for (int i = 1; i < tamanho; i++) {
        if (array[i] < *menor) {
            *menor = array[i];
        } else if (array[i] > *maior) {
            *maior = array[i];
        }
    }
}

int main() {
 
    int meuArray[] = {5, 7, 9, 6};
    int tamanho = sizeof(meuArray) / sizeof(meuArray[0]);

    int menor, maior;
    menor_maior_array(meuArray, tamanho, &menor, &maior);

    printf("Menor elemento do array: %d\n", menor);
    printf("Maior elemento do array: %d\n", maior);

    return 0;
}