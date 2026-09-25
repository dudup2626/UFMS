#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*
Escreva uma função que receba um número inteiro positivo na base decimal e imprima
sua representação em uma das seguintes bases numéricas: binário, octal ou hexadecimal.
A conversão deve ser feita através de sucessivas divisões do número pela base desejada,
armazenando os restos dessas divisões.
Implemente um programa que permita ao usuário escolher a base para conversão:
(a) Decimal para Binário (b) Decimal para Octal (c) Decimal para Hexadecimal
Dica: Utilize uma pilha para armazenar os restos das divisões e formar a representação
final do número na base escolhida.
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
    int n, i, resto, k;
    char base;
    PilhaV pv;
    inicializaV (&pv);
    k = 0;

    scanf("%d", &n);

    printf("== ESCOLHA A BASE ==\n");
    printf("== (a) decimal para binario\n");
    printf("== (b) decimal para octal\n");
    printf("== (c) decimal para hexadecimal\n:");
    scanf(" %c", &base);
    
    switch(base){
        case 'a':
            while(n > 0){
                resto = n % 2;
                pushV(&pv, resto);
                n = n / 2;
                k++;
            }
            printf("\ndec para bin: ");
            for(i=0; i<k; i++){
                resto = popV(&pv);
                printf("%d", resto);
            }

            break;

        /*case 'b':

            break;

        case 'c':

            break;*/
        
        default:
            printf("erro\n");
    }

    return 0;
}
