/*
Escreva um algoritmo que, dadas três fichas de produtos de um supermercado, 
contendo seu código, sua descrição e seu preço unitário, ordene as fichas em ordem 
não decrescente de código. Lembre-se de escrever também a definição do registro.
*/

#include <stdio.h>

typedef struct {
    int cod;
    char descricao[50];
    float preco;
} Produto;

void preencher_fichas(Produto p[3]){
    int i;

    for(i = 0; i < 3; i++){
        printf("\nDigite o codigo do produto %d: ", i + 1);
        scanf("%d", &p[i].cod);
        printf("Digite a descricao do produto %d: ", i + 1);
        scanf(" %[^\n]s", p[i].descricao);
        printf("Digite o preco do produto %d: ", i + 1);
        scanf("%f", &p[i].preco);
    }
}

void ordenar_fichas(Produto p[3]){
    int i, j;
    Produto temp;

    for(i = 0; i < 2; i++){
        for(j = i + 1; j < 3; j++){
            if(p[i].cod > p[j].cod){
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    printf("\nFichas ordenadas por codigo:\n");
    for(i = 0; i < 3; i++){
        printf("Codigo: %d, Descricao: %s, Preco: %.2f\n", p[i].cod, p[i].descricao, p[i].preco);
    }
}

int main(void){
    Produto p[3];

    preencher_fichas(p);
    ordenar_fichas(p);

    return 0;
}