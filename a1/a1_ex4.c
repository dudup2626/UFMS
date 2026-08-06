/*
Faça um programa que calcule a soma dos n primeiros números primos,
sendo n um número informado pelo usuário.
*/

#include <stdio.h>

int primo(int n){
    int i, p = 1;

    for(i = 2; i < n; i++){
        if(n % i == 0){
            p = 0;
        }
    }
    return p;
}

int main(void){
    int n, x = 2, qtd = 0, soma = 0;
    scanf("%d", &n);

    while(qtd < n){
        if(primo(x) == 1){
            soma = soma + x;
            qtd++;
        }
        x++;
    }

    printf("A soma dos %d primeiros numeros primos e: %d\n", n, soma);
    
    return 0;
}