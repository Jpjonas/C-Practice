#include <stdio.h>
int main()
{
  //Exercicio 2

  //r == 1   repete a operacao
  //r == 0   finaliza a operacao
  int r = 1;

  //enquanto r e 1, repete a operacao
  while(r == 1)
  {
    int x = 100;
    //operacao
    do
    {
      //numeros pares
      if((x % 2) == 0)
      {
        //imprime numeros pares
        printf ("%d\n",x);
      }
      x++;
    }while(x <= 201);

    //pergunta pra repetir
    printf ("Repetir?: ");
    scanf("%d", &r);
  }
  return 0;
}
