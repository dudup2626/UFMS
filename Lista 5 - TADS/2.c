#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*
Escreva uma função que receba um vetor de inteiros com n elementos e inverta a ordem
dos elementos no vetor. Para realizar a inversão, utilize obrigatoriamente uma pilha.
Observação: Não é permitido criar outro vetor auxiliar; a inversão deve ser realizada
exclusivamente com a pilha.
*/

#define MAX 100

typedef int tipo_dado;

typedef struct{
    tipo_dado dados[MAX];
    int topo;
} PilhaV;

void inicializaV(PilhaV *p){
    p->topo = -1;
}

void pushV(PilhaV *p, tipo_dado x){
    if(p->topo < MAX - 1){
        p->topo = p->topo + 1;
        p->dados[p->topo] = x;
    }
}

int popV(PilhaV *p){
    int r;
    if(p->topo != -1){
        r = p->dados[p->topo];
        p->topo = p->topo - 1;
    } else {
        r = INT_MIN;
    }
    return r;
}

int main(void)
{
    int n, i, *v;
    PilhaV pv;
    inicializaV (&pv);

    scanf("%d", &n);

    v = (int *) malloc(n * sizeof(int));
    if(v == NULL)
        return 1;
    
    for(i=0; i<n; i++){
        scanf("%d", &v[i]);
        pushV(&pv, v[i]);
    }

    printf("vetor antes: ");
    for(i=0; i<n; i++){
        printf("%d ", v[i]);
        v[i] = popV(&pv);
    }

    printf("\nvetor depois: ");
    for(i=0; i<n; i++){
        printf("%d ", v[i]);
    }
    
    free(v);

    return 0;
}
