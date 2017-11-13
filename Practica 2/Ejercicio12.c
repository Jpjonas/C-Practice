#include <stdio.h>

int main(){
    int n;
    printf("Número: ");
    scanf("%d",&n);

    int lnum[10];
    printf("Lista de números: ");
    for(int x=0; x<10; x++){
        scanf("%d",&lnum[x]);
    }

    for(int x=0; x<10; x++){
        if(lnum[x] == n){
            printf("%d", x);
            return 0;
        }
    }
    printf("-1");
    return 0;
}
