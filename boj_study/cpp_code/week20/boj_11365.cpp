#include <iostream>
#include<vector>
#include <string>

using namespace std;

int main()
{
  while(1)
  {
    string str;
    getline(cin,str);
    if (str=="END")
    {
      return (0);
    }
    for (int i = str.size()-1; i >= 0; i--)
    {
      cout<<str[i];
    }
    cout<<"\n";
  }
  return 0;
}