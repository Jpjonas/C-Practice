#include "stdio.h"
#include "string.h"

int main()
{
  int x, abc;
  char temp[6];
  char cadena[6] = "bucle\0";
  char letra='T';
  for(x=5;x>=1;x--) {
    printf("%s %d %c\n",strncpy(temp,cadena,5-x+1),x, x % 2 == 0 ? ((letra-(5-x))+32) :(letra-(5-x)) );
  }
  return 0;
}
