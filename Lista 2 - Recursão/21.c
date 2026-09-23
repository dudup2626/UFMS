#include <stdio.h>
#include <stdlib.h>

void inverte(int v[], int inicio, int fim){
    if(inicio >= fim)
        return;
    
    int aux;
    aux = v[inicio];
    v[inicio] = v[fim];
    v[fim] = aux;
    
    inverte(v, inicio + 1, fim - 1);
}

int main()
{
    int n;
    scanf("%d", &n);
    
    int *v;
    v = (int *) malloc(n * sizeof(int));
    if(v == NULL)
        return 1;
    
    for(int i=0; i<n; i++)
        scanf("%d", &v[i]);
    
    printf("vetor normal: ");
    for(int i=0; i<n; i++)
        printf("%d ", v[i]);
        
    inverte(v, 0, n - 1);
        
    printf("\nvetor invertido: ");
    for(int i=0; i<n; i++)
        printf("%d ", v[i]);
    
    free(v);

    return 0;
}
