#include <stdio.h>
#include <stdlib.h>

  void string_reverse(char* str){
    
  }

  int stringlen(char* str){
    int len=0;
    while(str[len]){
      len++;
    }
    return len;

  }

int main(){
  char *nome = "Jonas";
  int cmp = stringlen(nome);
  printf("%d\n",cmp );
  return 0;
}
