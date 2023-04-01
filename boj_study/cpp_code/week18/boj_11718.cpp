
#include <stdio.h>
//using namespace std;

int main()
{
  while(1)
  {
    char c;
    if (scanf("%c", &c) == -1)
    {
      return 0;
    }
      
    printf("%c", c);
  }

  return 0;
}