#include <stdio.h>

//Representamos años mediante números enteros
//main : int
//El usuario ingresa el año y el programa verifica si es o no bisiesto
//ent: 2016, salida Es bisiesto.
//ent: 2017, salida No es bisiesto.
//ent: 2018, salida No es bisiesto.
int main(){
    int ano;
    printf("Ingrese el año: ");
    scanf("%d",&ano);
    getchar();

    if(ano%400 == 0){
        printf("Es bisiesto.");
        getchar();
        return 0;
    }
    if(ano%4 == 0){
        if(ano%100 == 0){
        printf("No es bisiesto.");
        }
        else{
            printf("Es bisiesto.");
        }
    }
    else{
        printf("No es bisiesto.");
    }
    getchar();
    return 0;
}
