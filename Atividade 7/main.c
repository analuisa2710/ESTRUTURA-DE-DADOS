#include <stdio.h> 
#include "pilha.h" 
#include "fila.h" 

int main() { 
    /* Caso de uso para pilha: histórico de navegação na web */ 
    printf("\n--- Pilha: Historico de navegacao na web ---\n");
    char* paginasWeb[] = {"google.com", "bing.com", "github.com", "stackoverflow.com"};  	// Array com páginas da web visitadas 
    Pilha* p = cria_pilha();  	// Cria uma pilha 

    for (int i = 0; i < 4; i++) {  	// Percorre as páginas da web visitadas 
        printf("Navegando para %s\n", paginasWeb[i]);  	// Imprime que está navegando para a página da web i 
        push(p, paginasWeb[i]);  	// Adiciona a página da web i ao histórico de navegação 
    } 

    printf("Ultima pagina visitada: %s\n", pop(p));  	// Imprime a última página visitada e remove a página do topo do histórico de navegação 

    /* Caso de uso para fila: controle de impressão */ 
    printf("\n--- Fila: Controle de impressao ---\n");
    Fila* f = cria_fila();  	// Cria uma fila 

    /* Adiciona trabalhos na fila de impressão */ 
    for (int i = 1; i <= 5; i++) { 
        printf("Adicionando trabalho de impressao %d\n", i);  	// Imprime que está adicionando o trabalho de impressão i 
        enfileira(f, i);  	// Adiciona o trabalho de impressão i à fila 
    } 

    /* Executa trabalhos de impressão na ordem em que foram adicionados */ 
    while (f->inicio != f->fim) { 
        printf("Imprimindo trabalho %d\n", desenfileira(f));  	// Imprime que está imprimindo o trabalho e remove o trabalho do início da fila 
    } 

    libera_pilha(p);  	// Libera a memória alocada para a pilha 
    libera_fila(f);  	// Libera a memória alocada para a fila 

    return 0; 
} 