#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int main()
{
  while(1)
  {
    string n;
    cin>>n;
    if (!strcmp(n.c_str(),"0"))//
    {
      return 0;
    }
    int len = n.length()+1;
    for (int i = 0; i < n.length(); i++)
    {
      if(n[i] == '1')
      {
        len+=2;
      } else if (n[i] == '0')
      {
        len+=4;
      } else
      {
        len+=3;
      }
    }
    cout<<len<<"\n";


  }
  return 0;
}