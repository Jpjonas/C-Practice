#include <stdio.h>
int main()
{
  //Exercicio 4

  int x=1;
  double s=0;

  //Calcula serie
  while(x<=10)
  {
    s = s + x/(2*x-1);

    x=x+1;
  }

  //imprime resultado
    printf ("%d\n",s);

  return 0;
}
