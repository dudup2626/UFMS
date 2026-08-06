/*
Escreva uma função que encontre o maior e o menor valor em um conjunto
de n números reais armazenados em um vetor.
*/

#include <stdio.h>

void Mm(float v[], int n, float *maior, float *menor){
    int i;
    *maior = v[0];
    *menor = v[0];

    for(i = 1; i < n; i++){
        if(v[i] > *maior){
            *maior = v[i];
        }
        if(v[i] < *menor){
            *menor = v[i];
        }
    }
}

int main(void){
    int i;
    float maior, menor, v[10];

    for(i = 0; i < 10; i++){
        scanf("%f", &v[i]);
    }

    Mm(v, 10, &maior, &menor);

    printf("Maior: %.2f\n", maior);
    printf("Menor: %.2f\n", menor);

    return 0;
}