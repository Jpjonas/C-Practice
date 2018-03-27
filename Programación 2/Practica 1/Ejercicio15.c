#include <stdio.h>

int maximo(int m, int n);

int main(){
    int m,n;

    printf("Ingrese un número: ");
    scanf("%d",&m);
    printf("Ingrese un número: ");
    scanf("%d",&n);

    int max;
    max = maximo(m,n);
    printf("%d", max);
    return 0;
}

int maximo(int m, int n){
    if(m==n)
        return 0;
    if(m>n)
        return m;
    else
        return n;
}
