#include <stdio.h>
int main()
{
  //Exercicio 2

  //r == 1 (SIM)   repete a operacao
  //r == 0 (NAO)   finaliza a operacao
  int r = 1;


  //enquanto r e 1, repete a operacao
  while(r == 1)
  {
    int n;
    long factorial = 1;

    //pergunta o numero
    printf("Digite un numero: ");
    scanf("%d",&n);

    //calcula o fatorial
    for(i=1; i<=n; ++i)
        {
            f *= i;// factorial = factorial*i;
        }
        printf("\n%llu",factorial);

    //pergunta pra repetir
    printf ("Repetir?: ");
    scanf("%d", &x);
  }
  return 0;
}
