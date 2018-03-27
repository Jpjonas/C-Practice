#include <stdio.h>

int main(){
    int Edad;
    scanf("%d", &Edad);
    if (Edad > 64) {
        printf ("Seguridad Social");
    }
    else{
        if (Edad < 18){
            printf ("Exento");
        }
        else{
            printf ("Imposible");
        }
    }
    return 0;
}
