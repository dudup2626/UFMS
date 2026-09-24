#include <stdio.h>
#include <stdlib.h>

int *maximo(int n, int v[]){
    int *p, *maior;

    maior = v;
    
    for(p=v; p<v + n; p++){
        if(*p > *maior)
            maior = p;
    }

    return maior;
}

int main(void)
{
    int n, i, *v, *maior;

    scanf("%d", &n);
    v = (int*) malloc(n * sizeof(int));
    if(v == NULL)
        return 1;

    for(i=0; i<n; i++)
        scanf("%d", &v[i]);
    
    maior = maximo(n, v);
    printf("o endereço do maior(%d) é: %p", *maior, (void*)maior); 

    free(v);

    return 0;
}