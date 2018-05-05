#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int stringlen(char* str){
    int len=0;
    while(str[len]){
      len++;
    }
    return len;

}

void string_reverse(char* str){
    int i, tamStr = stringlen(str);
    char temp[tamStr];
    for(i=0;i<tamStr;i++)
      temp[tamStr-i] = str[i];
    strcpy(str,temp);
}

int string_concat(char* str1, char* str2, int max){
  int i, tamStr1 = stringlen(str1), tamStr2 = stringlen(str2);
  if(tamStr2>max)
    tamStr2 = max;
  for(i=0; i<tamStr2; i++){
    str1 = (char *) realloc(str1,sizeof(char));
    str1[i+tamStr1] = str2[i]
  }
  return i;
}

int string_subcadena(char* str1, char* str2){
  int i=0, ret =-1; tamStr1 = stringlen(str1);

  while((i < tamStr1) || (ret != -1)){


  }
}

/*
int string_compare(char* str1, char* str2){
    int i, max = stringlen(str1);
    if(stringlen(str2)<max)
      max = stringlen(str2);
    for(i=0; i<max; i++){
      if(str1[i]>str2[i])
        return 1;
      else{
        if(str1[i])
      }
    }

}*/

int main(){
  char *nome = "Jonas";
  int cmp = stringlen(nome);
  printf("%d\n",cmp );
  return 0;
}
