#include <stdio.h>
int main()
{
  //Exercicio 3

  int x=0;
  int y=0;
  int n=0;

  //pergunta os numeros
  printf ("Primeiro numero: ");
  scanf("%d", &x);
  printf ("Segundo numero: ");
  scanf("%d", &y);

  //calcula exponencial
  int r=x;
  while(n<y)
  {
    r = r*x;
    n++;
  }

  //imprime resultado
  printf ("%d\n",r);

  return 0;
}
