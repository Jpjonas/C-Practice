#include <stdio.h>
int main()
{
  int n=0,s1=0;
  for(n=1;n<=100;n++)
  {
    s1 += 1/n;
  }
  printf("%d\n",s1);

  int k=0,s2=0;
  for(k=1;k<=30;k++)
  {
    s2 += 1/(k*k);
  }
  printf("%d\n",s2);

  /*
  int j=0,s3=0;
  for(j=1;j<=25;j++)
  {
    s3 += 1/(j^j);
  }
  printf("%d\n",s3);
  */

  int i=0,s4=0;
  for(i=2;i<=10;i++)
  {
    s4 += (i+1)*i;
  }
  printf("%d\n",s4);


  return 0;
}
