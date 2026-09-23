#include <stdio.h>
#include <stdlib.h>
/*
Escreva um programa que leia uma sequência de números inteiros, parando a leitura
imediatamente quando o usuário digitar o valor 0. Em seguida, chame a função criada no
exercício anterior para imprimir os números lidos em ordem reversa. Regra: O controle
da posição durante a leitura dos dados também deve ser feito exclusivamente com um
ponteiro. Considere que, no máximo, serão fornecidos 100 números.
*/

void imprimeV(int v[], int n){
    if(n <= 0){
        printf("0");
    }
    else{
        int *p;
        p = &v[n - 1];
        printf("\ninvertido: ");
        for(int i=0; i<n; i++){
            printf("%d ", *p);
            p--;
        }
    }
}


int main(void) {
    int v[100], *j, total = 0;
    j = v;

    for(int i=0; i<100; i++){
        scanf("%d", j);
        if(*j == 0)
            i = 100;
        else{        
            j++;
            total++;
        }
    }

    imprimeV(v, total);

    return 0;
}