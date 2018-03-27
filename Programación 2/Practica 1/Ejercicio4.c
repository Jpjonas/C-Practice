#include <stdio.h>

int determinaEstadoAgua(int t)
{
  if(t<=0)
  {
    printf("Solido");
  }
  else
  {
    if(t>=100)
    {
      printf("Gas");
    }
    else
    {
      printf("Liquido");
    }
  }
  return 0;
}

int main()
{
  int t=0;
  printf("Ingrese la temperatura: ");
  scanf("%d",&t);
  determinaEstadoAgua(t);

  return 0;
}
