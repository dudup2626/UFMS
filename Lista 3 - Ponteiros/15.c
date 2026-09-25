#include <stdio.h>
#include <stdlib.h>

/*
Escreva uma função que receba um número intero n, com 1 ≤ n ≤ 100, e um vetor v com
n > 0 números inteiros e devolva um maior e um segundo maior elementos desse vetor.
Sua função deve ter a seguinte interface:
void dois_maiores(int n, int v[], int *p_maior, int *s_maior)
*/

void dois_maiores(int n, int v[], int *p_maior, int *s_maior){
    int *p;
    p = v;

    for(p=v; p<v + n; p++)
        if(*p > *p_maior)
            *p_maior = *p;        
    
    for(p=v; p<v + n; p++)
        if(*p > *s_maior && *p_maior > *p)
            *s_maior = *p;

    printf("1º maior: %d\n", *p_maior);
    printf("2º maior: %d\n", *s_maior);
}

int main(void)
{
    int n, i;
    int *v;
    int p_maior, s_maior;

    scanf("%d", &n);
    v = (int *) malloc(n * sizeof(int));
    if(v == NULL)
        return 1;
    for(i=0; i<n; i++)
        scanf("%d", &v[i]);

    if(n < 1 || n > 100)
        printf("invalido\n");
    else{
        p_maior = v[0];
        s_maior = v[0];
        dois_maiores(n, v, &p_maior, &s_maior);
    }

    free(v);

    return 0;
}