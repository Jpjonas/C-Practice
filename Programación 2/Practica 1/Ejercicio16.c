#include <stdio.h>

int verificaTriangulo(int m, int n, int l);
int verificaTrianguloRetegulo(int m, int n, int l);

#define ESTRIANGULO 1;
#define NOESTRIANGULO 0;
#define ESTRIANRET 1;
#define NOESTRIANRET 0;

//Ejercicios 16 y 17
int main(){
    int m,n,l;

    printf("Ingrese un número: ");
    scanf("%d",&m);
    printf("Ingrese un número: ");
    scanf("%d",&n);
    printf("Ingrese un número: ");
    scanf("%d",&l);

    if(verificaTriangulo(m,n,l) == 1){
        if(verificaTrianguloRetegulo(m,n,l) ==1){
            printf("Triangulo Retangulo");
        }
    }
    return 0;
}

int verificaTriangulo(int m, int n, int l){
    if(m+n>l || n+l>m || m+l>n){
        return ESTRIANGULO;
    }
    return NOESTRIANGULO;
}

int verificaTrianguloRetegulo(int m, int n, int l){
    if(m*m+n*n == l*l || n*n+l*l == m*m || m*m+l*l == n*n){
        return ESTRIANRET;
    }
    return NOESTRIANRET;
}
