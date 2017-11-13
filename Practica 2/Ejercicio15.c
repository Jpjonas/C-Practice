#include <stdio.h>

int main(){
    int n;
    printf("Número: ");
    scanf("%d",&n);

    int lnum[n];
    printf("Lista de números: ");
    for(int x=0; x<n; x++){
        scanf("%d",&lnum[x]);
    }

    int suma=0;
    for(int x=0; x<n; x++){
        suma += lnum[x];
    }
    printf("\n%d",suma);
    return 0;
}
