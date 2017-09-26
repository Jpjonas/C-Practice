#include <stdio.h>
int main()
{
  //Exercicio 1

  int x;
  //percorre vinte primeiros numeros
  for(x=1;x<=20;x++)
  {
    //filtra numeros impares
    if((x % 2) != 0)
    {
      //imprime numeros impares
      printf ("%d\n",x);
    }
  }
  return 0;
}
