#include <stdio.h>
#include <stdlib.h>
/*
Escreva uma função que receba três parâmetros: um vetor de inteiros, o seu tamanho e
um caractere indicando a direção ('+' para ordem normal ou '-' para ordem reversa).
A função deve percorrer e imprimir o vetor na direção escolhida. Regra: É proibido usar
índices. O acesso deve ser feito apenas através de aritmética de ponteiros.
*/

void imprimeV(int v[], int n, char d){
    int *p;
    if(d == '+'){
        p = v;
        printf("\nnormal: ");
        for(int i=0; i<n; i++){
            printf("%d ", *p);
            p++;
        }
    } else{
        if(d == '-'){
            p = &v[n - 1];
            printf("\ninvertido: ");
            for(int i=0; i<n; i++){
                printf("%d ", *p);
                p--;
            }
        }
        else
            printf("invalido\n");
    }
}


int main(void) {
    int tam;
    char dir;
    scanf("%d", &tam);
    int *v;
    v = (int*) malloc(tam * sizeof(int));
    if(v == NULL)
        return 1;

    for(int i=0; i<tam; i++)
        scanf("%d", &v[i]);
    
    scanf(" %c", &dir);

    imprimeV(v, tam, dir);

    return 0;
}