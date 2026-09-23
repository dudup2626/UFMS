#include <stdio.h>

void digito(int n, int i){
    if(n == i)
        printf("%d\n", i);
    else{
        printf("%d\n", i);
        digito(n , i + 1);
    }
}


int main(void){
    int n, i;
    printf("insira o n da contagem: ");
    scanf("%d", &n);
    i = 1;

    digito(n, i);

    return 0;
}