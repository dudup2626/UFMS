/*
Você foi encarregado de criar um pequeno filtro de dados demográficos para n cidades (n ≤ 1000). 
O algoritmo deve ler o nome, a sigla do estado e a população de cada cidade. 
Após ler todos os dados, o programa deve emitir um relatório contendo:

Os nomes de todas as cidades pertencentes ao estado de Mato Grosso do Sul (MS).
Os dados completos da cidade (ou cidades, em caso de empate) que possui a maior população global.
*/

#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    char sigla_estado[3];
    int pop;
} Cidade;

void Le_cidades(Cidade c[1000], int n){
    int i;

    for(i = 0; i < n; i++){
        scanf(" %[^\n]s", c[i].nome);
        scanf(" %[^\n]s", c[i].sigla_estado);
        scanf("%d", &c[i].pop);
    }
}

void Mostra_cidades_MS(Cidade c[1000], int n){
    int i;

    for(i = 0; i < n; i++){
        if(strcmp(c[i].sigla_estado, "MS") == 0){
            printf("%s\n", c[i].nome);
        }
    }
}

void Maior_populacao(Cidade c[1000], int n){
    int i, maior = 0;

    for(i = 0; i < n; i++){
        if(c[i].pop > maior){
            maior = c[i].pop;
        }
    }

    for(i = 0; i < n; i++){
        if(c[i].pop == maior){
            printf("%s %s %d\n", c[i].nome, c[i].sigla_estado, c[i].pop);
        }
    }
}

int main(void){
    int n;
    Cidade c[1000];

    printf("Digite o numero de cidades: ");
    scanf("%d", &n);

    Le_cidades(c, n);
    Mostra_cidades_MS(c, n);
    Maior_populacao(c, n);

    return 0;
}