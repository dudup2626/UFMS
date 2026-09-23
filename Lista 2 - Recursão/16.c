#include <stdio.h>

int digitos(int n){
    if(n < 10)
        return 1;
    else
        return digitos(n / 10) + 1;
}

int main()
{
    int n, dig;
    
    scanf("%d", &n);
    dig = digitos(n);
    printf("\ndigitos: %d", dig);
}
