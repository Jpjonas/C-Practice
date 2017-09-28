#include <stdio.h>
int main()
{
  //Exercicio 6

  //r == 1 (SIM)   repete a operacao
  //r == 0 (NAO)   finaliza a operacao
  int r=1;


  //enquanto r e 1, repete a operacao
  while(r == 1)
  {
    int n;
    int f=1;

    //pergunta o numero
    printf("Digite un numero: ");
    scanf("%d",&n);

    //calcula o fatorial
    int i=0;
    for(i=1; i<=n; ++i)
    {
        f *= i; // f = f*i;
    }
    //imprime factorial
    printf("\nFatorial: %d",f);

    //pergunta pra repetir
    printf ("\nRepetir?: ");
    scanf("%d", &r);
  }
  return 0;
}
