#include <stdio.h>

int diaPascua(int ano);

int main(){
    int ano;

    printf("Ingrese un año: ");
    scanf("%d",&ano);

    int dia;
    dia = diaPascua(ano);
    printf("Dia pascua: %d", dia);
    return 0;
}

int diaPascua(int ano){
    return 22 + (19*ano + 24) + (2*ano + 4*ano + 6*(19*ano + 24) +5);
}
