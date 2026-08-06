/*
Escreva uma função que receba dois números a e b e responde se a é
permutação de b. Um número a é dito ser permutação de um número b
se os dígitos de a formam uma permutação dos dígitos de b. Considere
que o dígito 0 não aparece nos números.

Exemplo: 5412434 é uma permutação de 4321445, mas não é uma per-
mutação de 4312455.
*/

#include <stdio.h>

void verifica_permutacao(int a, int b, int tam_a, int tam_b){
    int i, cont = 0;
    int digitos_a[10], digitos_b[10];

    if(tam_a != tam_b){
        printf("Nao sao permutacoes\n");
        return;
    }

    while(a > 0){
        digitos_a[cont] = a % 10;
        cont++;
        a /= 10;
    }

    while(b > 0){
        digitos_b[cont] = b % 10;
        cont++;
        b /= 10;
    }

    for(i = 0; i < tam_a; i++){
        if(digitos_a[i] != digitos_b[i]){
            printf("Nao sao permutacoes\n");
            return;
        }
    }

    printf("Sao permutacoes\n");
    
}

int conta_digitos(int n){
    int cont = 0;
    
    while(n > 0){
        n = n % 10;
        cont++;
    }
    
    return cont;
}


int main(void){
	int a, b, tam_a, tam_b;
    scanf("%d %d", &a, &b);

    tam_a = conta_digitos(a);
    tam_b = conta_digitos(b);

    verifica_permutacao(a, b, tam_a, tam_b);
	
	return 0;
}