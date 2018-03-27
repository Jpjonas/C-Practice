#include <stdio.h>

//Contar los números impaares de cero a cien
int main(){
    int i=1;
    while(i<=100){
        if(i%2 != 0){
            printf("%d\n", i);
        }
        i++;
    }
    return 0;
}
