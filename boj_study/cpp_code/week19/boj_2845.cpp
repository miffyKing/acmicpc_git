#include <iostream>

using namespace std;

int main()
{

  int l, p;
  int people[5];
  cin>>l>>p;
  for (int i = 0; i < 5; i++)
  {
    cin>>people[i];
  }
  int total = l*p;
  for (int i = 0; i < 5; i++)
  {
    cout<<people[i] - total << ' ';
  }
  return 0;
}