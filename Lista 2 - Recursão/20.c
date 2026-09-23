#include <stdio.h>

int digito(int n, int i){
    if(i >= n)
        if(i - 1 == n)
            return 0;
        else
            return 1;
    else{
        return digito(n, i + 1) + digito(n, i + 2);
    }
}


int main(void){
    int n, man, i;
    printf("insira o n da amarelinha: ");
    scanf("%d", &n);
    i = 0;

    man = digito(n, i);
    printf("Há %d maneiras de cruzar a amarelinha\n", man);

    return 0;
}