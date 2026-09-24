#include <stdio.h>
#include <stdlib.h>

void soma_prod(int a, int b, int *soma, int *prod){
    *soma = a + b;
    *prod = a * b;
}

int main(void)
{
    int a, b, soma, prod;
    scanf("%d", &a);
    scanf("%d", &b);

    soma_prod(a, b, &soma, &prod);

    printf("soma: %d\nproduto: %d\n", soma, prod);

    return 0;
}