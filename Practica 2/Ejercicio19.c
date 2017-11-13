#include <stdio.h>

int main(){
    char c;
    printf("Caracter: ");
    scanf("%c",&c);

    char str[20];
    printf("String: ");
    scanf("%s",str);

    int count=0;
    for(int x=0; x<20; x++){
        if(str[x] == c){
            count++;
        }
    }
    printf("%d\n", count);
    return 0;
}
