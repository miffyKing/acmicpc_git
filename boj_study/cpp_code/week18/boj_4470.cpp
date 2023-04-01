#include <iostream>
#include <string.h>

using namespace std;

int main()
{
  int n;
  cin>>n;
  string tmp;
  getline(sin,tmp);
  
  for (int i = 1; i <= n; i++)
  {
    string s;
    getline(cin, s);
    cout << i << "." << s <<"\n";
  }
}