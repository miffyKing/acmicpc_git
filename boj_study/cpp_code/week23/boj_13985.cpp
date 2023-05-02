#include <iostream>

using namespace std;

int main()
{

  int a,b,c;
  string input;

  getline(cin, input);
  a = input[0] - '0';
  b = input[4] - '0';
  c = input[8] - '0'; 
  //cout<< a << " " << b << " " << c<<"\n";
  if (a + b == c)
  {
    cout<<"YES\n";
    return 0;
  }
  cout<<"NO\n";
  return 0;
}