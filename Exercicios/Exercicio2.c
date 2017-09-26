#include <stdio.h>
int main()
{
  //Exercicio 2

  //r == 1   repete a operacao
  //r == 0   finaliza a operacao
  int r = 1;
  int x = 100;
  //enquanto r e 1, repete a operacao
  while(r == 1)
  {
    //operacao
    do
    {
      //numeros pares
      if((x % 2) == 0)
      {
        //imprime numeros impares
        printf ("%d\n",x);
      }
    }while(x <= 200)

    //pergunta pra repetir
    printf ("Repetir?: ");
    scanf("%d", &x);
  }
  return 0;
}
