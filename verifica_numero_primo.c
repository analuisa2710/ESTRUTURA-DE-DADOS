#include <stdio.h>

int ehPrimo(int numero) {
    if (numero <= 1) {
        return 0; 
    }
    for (int i = 2; i * i <= numero; i++) {
        if (numero % i == 0) {
            return 0; 
        }
    }
    return 1; 
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <numero>\n", argv[0]);
        return 1;
    }

    int numero = atoi(argv[1]);

    if (ehPrimo(numero)) {
        printf("1\n");
    } else {
        printf("0\n");
    }

    return 0;
}
