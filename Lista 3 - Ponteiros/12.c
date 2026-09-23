#include <stdio.h>
#include <stdlib.h>
/*
Escreva um programa que leia um número inteiro N (tamanho do vetor), aloque memória
dinamicamente para um vetor de N inteiros e guarde os N valores digitados pelo usuário.
Por fim, imprima o vetor completo na tela e exiba a soma de todos os números ímpares
presentes nele.
*/

int Impares(int v[], int n){
    int S = 0;
    for(int i = 0; i<n; i++){
        if(v[i] % 2 == 1)
            S = S + v[i];
    }
    return S;
}

int main(void) {
    int n, soma;

    scanf("%d", &n);
    int *v;
    v = (int *) malloc(n * sizeof(int));
    if(v == NULL)
        return 1;

    for(int i=0; i<n; i++){
        scanf("%d", &v[i]);
    }

    printf("Vetor: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    soma = Impares(v, n);
    printf("Soma dos impares: %d\n", soma);

    free(v);

    return 0;
}