#include <stdio.h>

//Número primo
int main(){
    int n;
    printf("Ingrese un número: ");
    scanf("%d",&n);

    double fac=1;//double
    while(n>0){
        fac = fac * n;
        n--;
    }
    printf("\nFactorial: %f", fac);
    return 0;
}
