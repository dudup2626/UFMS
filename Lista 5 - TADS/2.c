#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*
Escreva uma função que receba um vetor de inteiros com n elementos e inverta a ordem
dos elementos no vetor. Para realizar a inversão, utilize obrigatoriamente uma pilha.
Observação: Não é permitido criar outro vetor auxiliar; a inversão deve ser realizada
exclusivamente com a pilha.
*/

void push(int *t, int P[], int y, int n){
    if(*t != n - 1){
        (*t)++;
        P[*t] = y;
    }
}

int pop(int *t, int P[], int n){
    int r;
    if(*t != -1){
        r = P[*t];
        (*t)--;
    } 
    else
        r = INT_MIN;
    
    return r;
}

int main(void)
{
    int n, i, *v;
    int *P, t;

    scanf("%d", &n);
    P = (int *) malloc(n * sizeof(int));
    t = -1;
    if(P == NULL)
        return 1;

    v = (int *) malloc(n * sizeof(int));
    if(v == NULL)
        return 1;
    
    for(i=0; i<n; i++){
        scanf("%d", &v[i]);
        push(&t, P, v[i], n);
    }

    printf("vetor antes: ");
    for(i=0; i<n; i++){
        printf("%d ", v[i]);
        v[i] = pop(&t, P, n);
    }

    printf("\nvetor depois: ");
    for(i=0; i<n; i++){
        printf("%d ", v[i]);
    }
    

    free(P);
    free(v);

    return 0;
}