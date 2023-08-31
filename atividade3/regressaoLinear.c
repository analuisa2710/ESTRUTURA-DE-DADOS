#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    double y;
} Ponto;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <dados.csv>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo %s\n", argv[1]);
        return 1;
    }

    int n = 0;
    while (!feof(fp)) {
        if (fgetc(fp) == '\n') n++;
    }
    rewind(fp);

    Ponto *pontos = malloc(n * sizeof(Ponto));
    for (int i = 0; i < n; i++) {
        fscanf(fp, "%d,%lf\n", &pontos[i].x, &pontos[i].y);
    }
    fclose(fp);

    double media_x = 0, media_y = 0;
    for (int i = 0; i < n; i++) {
        media_x += pontos[i].x;
        media_y += pontos[i].y;
    }
    media_x /= n;
    media_y /= n;

    double num = 0, den = 0;
    for (int i = 0; i < n; i++) {
        num += (pontos[i].x - media_x) * (pontos[i].y - media_y);
        den += (pontos[i].x - media_x) * (pontos[i].x - media_x);
    }
    double inclinacao = num / den;

    double intercepcao = media_y - inclinacao * media_x;

    printf("Equacao da regressao linear: y = %lfx + %lf\n", inclinacao, intercepcao);

    free(pontos);
    return 0;
}