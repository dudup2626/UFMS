/*
O setor de compras de uma loja precisa gerar duas listagens distintas a partir do cadastro 
de seus produtos:
⬩ Urgente: produtos com estoque atual abaixo do estoque mínimo.
⬩ Atenção: produtos com estoque atual igual ou acima do estoque mínimo, mas com no máximo 5% de sobra.

Cada produto possui código, descrição, preço, estoques mínimo e atual.
Como o orçamento está curto, a loja decidiu contratar apenas uma função para 
realizar esse trabalho. Sua tarefa é desenvolver uma única função capaz de percorrer 
o vetor de produtos e imprimir apenas aqueles que atendam ao critério solicitado.

A função deve ser genérica e reutilizável, permitindo que o programa principal gere 
diferentes relatórios apenas alterando os argumentos da chamada, sem modificar seu código. 
Sua implementação também deve facilitar a utilização de novas faixas percentuais 
em relação ao estoque mínimo.
*/

#include <stdio.h>

typedef struct{
    int cod;
    char desc[50];
    float preco;
    int est_min;
    int est_atual;
} Produto;

void Preenche_produtos(Produto p[10]){
    int i;
    for(i=0; i<10; i++){
        printf("Digite o código do produto %d: ", i+1);
        scanf("%d", &p[i].cod);
        printf("Digite a descrição do produto %d: ", i+1);
        scanf(" %49[^\n]", p[i].desc);
        printf("Digite o preço do produto %d: ", i+1);
        scanf("%f", &p[i].preco);
        printf("Digite o estoque mínimo do produto %d: ", i+1);
        scanf("%d", &p[i].est_min);
        printf("Digite o estoque atual do produto %d: ", i+1);
        scanf("%d", &p[i].est_atual);
        printf("\n");
    }
}

void Listagem_distinta(Produto p[], int m, float percent){
    int i;

    /*Mostra urgente*/
    if(m == 1 || m == 3){
        printf("Produtos em Urgencia: \n");
        for(i=0; i<10; i++){
            if(p[i].est_atual < p[i].est_min){
                printf("Codigo: %d\nDescricao: %s\nPreco: %.2f\nEstoque minimo: %d\nEstoque atual: %d\n", 
                p[i].cod, p[i].desc, p[i].preco, p[i].est_min, p[i].est_atual);
            }
        }
    }

    /*Mostra os atencao*/
    if(m == 2 || m == 3){
        printf("Produtos com Atencao: \n");
        for(i=0; i<10; i++){
            if(p[i].est_atual >= p[i].est_min && p[i].est_atual <= p[i].est_min * (1 + percent / 100.0)){
                printf("Codigo: %d\nDescricao: %s\nPreco: %.2f\nEstoque minimo: %d\nEstoque atual: %d\n", 
                p[i].cod, p[i].desc, p[i].preco, p[i].est_min, p[i].est_atual);
            }
        }
    }
}

int main(void){
    int modo;
    float percent;
    Produto p[10];
    scanf("%f", &percent);
    scanf("%d", &modo);
    Preenche_produtos(p);

    while(modo < 0 || modo > 3){
        printf("Digite 1 para listar produtos em Urgencia\n");
        printf("Digite 2 para listar produtos com Atencao\n");
        printf("Digite 3 para listar os dois\n");
        printf("Digite 0 para sair: \n");
        scanf("%d", &modo);

        if(modo != 0){
            Listagem_distinta(p, modo, percent);
        }
    }

    return 0;
}