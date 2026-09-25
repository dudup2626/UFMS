#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
Escreva uma função que receba duas strings e verifique se a segunda ocorre dentro da
primeira, retornando 1 (verdadeiro) se encontrar, ou 0 (falso) caso contrário. Regra:
Não utilize funções prontas da linguagem; o acesso e a comparação devem ser feitos
exclusivamente com aritmética de ponteiros.
*/

int Contido(char *s1, char *s2, int n1, int n2){
    char *p1, *p2, *aux;

    if(n2 > n1)
        return 0;

    p1 = s1;

    while(p1 <= s1 + (n1 - n2)){
        aux = p1;
        p2 = s2;

        while(p2 < s2 + n2 && *aux == *p2){
            aux++;
            p2++;
        }

        if(p2 == s2 + n2)
            return 1;

        p1++;
    }

    return 0;
}

int main(void){
    int n1, n2, vf;
    char *s1, *s2;

    scanf("%d %d", &n1, &n2);

    s1 = (char *) malloc((n1 + 1) * sizeof(char));
    if(s1 == NULL)
        return 1;
    s2 = (char *) malloc((n2 + 1) * sizeof(char));
    if(s2 == NULL)
        return 1;   

    scanf(" %[^\n]", s1);
    scanf(" %[^\n]", s2);

    vf = Contido(s1, s2, n1, n2);

    if(vf == 1)
        printf("%s está contido em %s\n", s1, s2);
    else
        printf("%s não está contido em %s\n", s1, s2);

    free(s1);
    free(s2);
    return 0;
}
