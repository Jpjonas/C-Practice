#include <stdio.h>

int main(){
    int mult3[50];
    int i=0,n=0;
    while(i<50){
        if(n%3 == 0){
            mult3[i] = n;
            i++;
        }
        n++;
    }
    for(int x=49;x>=0;x--){
        printf("\n%d",mult3[x]);
    }
    return 0;
}
