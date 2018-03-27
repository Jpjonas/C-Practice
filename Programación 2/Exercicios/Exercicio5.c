#include <stdio.h>
int main()
{
  //Exercicio 5

  int n;
  int primeiro = 0;
  int segundo = 1;
  int proximo;
  int c;

  //pergunta a quantidade de termos
  printf ("Quantidade de termos: ");
  scanf("%d", &n);

     for(c = 0;c < n;c++)
     {
        if(c <= 1)
           proximo = c;
        else
        {
           proximo = primeiro + segundo;
           primeiro = segundo;
           segundo = proximo;
        }
        printf("%d\n",proximo);
     }

  return 0;
}
