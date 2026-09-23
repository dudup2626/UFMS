#include <stdio.h>

void digito(int n){
    if(n == 0)
        printf("%d\n", n);
    else{
        printf("%d\n", n);
        digito(n - 1);
    }
}


int main(void){
    int n;
    printf("insira o n da contagem: ");
    scanf("%d", &n);

    digito(n);

    return 0;
}