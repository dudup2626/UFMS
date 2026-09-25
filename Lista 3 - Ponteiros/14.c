#include <stdio.h>
#include <stdlib.h>

/*
Escreva uma função que receba um número inteiro n, com 1 ≤ n ≤ 100, e um vetor v
com n > 0 números inteiros e devolva um maior e um menor dos elementos desse vetor.
Sua função deve ter a seguinte interface:
void min_max(int n, int v[ ], int *max, int *min)
*/

void min_max(int n, int v[], int *max, int *min){
    int *p;
    p = v;

    for(p=v; p < v + n; p++){
        if(*p > *max)
            max = p;
        if(*p < *min)
            min = p;
    }
    printf("maior: %d\n", *max);
    printf("menor: %d\n", *min);
}

int main(void){
    int n;
    int *v;
    int max, min;
    int i;

    scanf("%d", &n);
    v = (int *) malloc(n * sizeof(int));
    if(v == NULL)
        return 1;

    for(i=0; i<n; i++)
        scanf("%d", &v[i]);
    
    if(n < 1 || n > 100)
        printf("erro\n");
    else{
        max = v[0];
        min = v[0];
        min_max(n, v, &max, &min);
    }

    free(v);
    return 0;
}
