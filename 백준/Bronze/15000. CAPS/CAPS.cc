#include <iostream>
#include <string>

using namespace std;

int main()
{
  string a;
  cin>>a;

  for (int i = 0; i < a.length(); i++)
  {
    cout<< (char)toupper(a[i]);
  }

  return 0;
}