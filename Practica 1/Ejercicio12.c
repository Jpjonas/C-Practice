#include <stdio.h>

//Número primo
int main(){
    int n;
    printf("Ingrese un número: ");
    scanf("%d",&n);

    int i=2;
    while(i<n){
        if(n%i == 0){
            printf("No es primo");
            return 0;
        }
        i++;
    }
    printf("Es primo");
    return 0;
}
