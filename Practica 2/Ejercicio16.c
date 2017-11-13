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

    int mult=0;
    for(int x=0; x<n; x++){
        mult *= lnum[x];
    }
    printf("\n%d",mult);
    return 0;
}
