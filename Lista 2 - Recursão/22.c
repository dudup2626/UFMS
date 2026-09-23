#include <stdio.h>
#include <stdlib.h>

int media(int v[], int n){
    if(n == 0)
        return v[n];
    
    else
        return media(v, n - 1) + v[n];
}

int main()
{
    int n, m;
    scanf("%d", &n);
    
    int *v;
    v = (int *) malloc(n * sizeof(int));
    if(v == NULL)
        return 1;
    
    for(int i=0; i<n; i++)
        scanf("%d", &v[i]);
        
    m = media(v, n - 1) / n;
        
    printf("\nmedia de valores: ");
    printf("%d", m);
    
    free(v);

    return 0;
}
