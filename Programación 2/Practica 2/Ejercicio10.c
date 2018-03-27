#include <stdio.h>

int main(){
    int pares[50];
    int i=0;
    for(int x=0;x<100;x++){
        int n=x+100;
        if(n%2 == 0){
            pares[i] = n;
            i++;
        }
    }
    for(int x=49;x>=0;x--){
        printf("\n%d",pares[x]);
    }
    return 0;
}
