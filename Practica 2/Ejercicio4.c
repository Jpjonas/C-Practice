#include <stdio.h>

int main()
{
    int a,b,c;
    for(a=1;a<=20;a++)
    {
      for(b=1;b<=30;b++)
      {
        for(c=1;c<=((a*a)+(b*b));c++)
        {
          if(((a*a)+(b*b)==(c*c)))
          {
            printf("a=%d   b=%d   c=%d\n",a,b,c);
          }
        }
      }
    }
    return 0;
}
