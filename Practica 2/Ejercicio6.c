#include "stdio.h"

#define NUMSECRETO 325

int main()
{
  //adivinar valor entre 0 y 500
  for(int x=0;x<=15;x++)
  {
    printf("\nIngresse un valor entre 0 y 500: ");
    int n;
    scanf("%d",&n);
    if(n == NUMSECRETO)
    {
      printf("\n¡Ganou!\n");
      return 0;
    }
    else
    {
      if(n < NUMSECRETO)
      {
        printf("\nEl numero es mayor");
      }
      else
      {
        printf("\nEl numero es menor");
      }
    }
  }
  printf("\n¡No Ganou!\n");
  return 0;
}
