/*
Escreva uma função que receba um vetor de inteiros com n elementos e inverta a ordem
dos elementos no vetor. Para realizar a inversão, utilize obrigatoriamente uma pilha.
Observação: Não é permitido criar outro vetor auxiliar; a inversão deve ser realizada
exclusivamente com a pilha.
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef int tipo_dado;

typedef struct {
    tipo_dado dado[MAX];
    int topo;
} PilhaV;

void inicializaV(PilhaV *p){
    p->topo = -1;
}

void pushV(PilhaV *p, tipo_dado x){
    if(p->topo < MAX - 1){
        p->topo = p->topo + 1;
        p->dado[p->topo] = x;
    }
}

int popV(PilhaV *p){
    tipo_dado x;
    if(p->topo >= 0){
        x = p->dado[p->topo];
        p->topo = p->topo - 1;
        return x;
    }
}

int main(void) {
    int v[MAX], n, i;
    PilhaV p;
    inicializaV(&p);

    scanf("%d", &n);

    for(i=0; i<n; i++)
        scanf("%d",&v[i]);
    
    printf("\nvetor normal: ");
    for(i=0; i<n; i++)
        printf("%d ", v[i]);

    for(i=0; i<n; i++)
        pushV(&p, v[i]);

    for(i=0; i<n; i++)
        v[i] = popV(&p);

    printf("\nvetor invertido: ");
    for(i=0; i<n; i++)
        printf("%d ", v[i]);

    return 0;
}
