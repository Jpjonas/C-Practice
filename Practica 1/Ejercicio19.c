#include <stdio.h>

int fibonacci(int n);

int main(){
    int f,t;
    printf("Ingrese un número: ");
    scanf("%d",&t);
    f = fibonacci(t);
    printf("%d",f);
    return 0;
}

int fibonacci(int n){
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    if(n >= 2)
        return fibonacci(n-1)+fibonacci(n-2);
}
