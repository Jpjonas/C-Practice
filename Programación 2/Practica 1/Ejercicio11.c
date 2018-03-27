#include <stdio.h>

//Contar los números impaares de c hasta f
int main(){
    int c, f;
    printf("Inicio: ");
    scanf("%d",&c);
    printf("Final: ");
    scanf("%d",&f);
    int i=c;
    while(i<=f){
        printf("%d\n", i);
        i++;
    }
    return 0;
}
