#include <stdio.h>

int main(){
    char c;
    printf("Caracter: ");
    scanf("%c",&c);

    char str[20];
    printf("String: ");
    scanf("%s",str);

    for(int x=0; x<20; x++){
        if(str[x] == c){
            printf("Presente\n");
        }
    }
    return 0;
}
