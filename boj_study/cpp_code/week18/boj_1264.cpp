#include<iostream>
#include <string.h>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
  string s;
  while(1)
  {
    getline(cin, s);
    if ( s == "#")
    {
      return 0;
    }
    int cnt = 0;
    for (int i = 0; i < s.length(); i++)
    {
      if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') 
      {
        cnt++;
      } else if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') 
      {
        cnt++;
      }
    }
    cout<<cnt<<"\n";
  }
  return 0;
}