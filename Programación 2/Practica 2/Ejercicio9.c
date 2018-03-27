#include <stdio.h>

int main(){
    int nums[100];
    for(int x=0;x<100;x++){
        nums[x] = x;
    }
    for(int x=0;x<100;x++){
        printf("\n%d",nums[x]); 
    }
    return 0;
}
