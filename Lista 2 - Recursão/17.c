#include <stdio.h>

int ocorre(int n, int k){
    if(n < 10){
        if(n == k)
            return 1;
        else
            return 0;
    }
    else{
        if(n % 10 == k)
            return ocorre(n / 10, k) + 1;
        else
            return ocorre(n / 10, k);
    }
}

int main()
{
    int n, k, dig;
    
    printf("digite n(contem k): ");
    scanf("%d", &n);
    printf("digite k(contido em n): ");
    scanf("%d", &k);
    
    dig = ocorre(n, k);
    printf("\nocorrencias: %d", dig);
    
    return 0;
}