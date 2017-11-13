#include <stdio.h>

int main(){
    char str[20];
    printf("String: ");
    scanf("%s",str);

    int count=0;
    for(int x=20; x>0; x--){
        printf("%c", str[x]);
        fflush(stdin);
    }
    return 0;
}
