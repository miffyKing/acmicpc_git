#include <iostream>

using namespace std;

int main()
{
  int n;
  cin>>n;

  int left= n%4;
  if (left == 1 || left == 3)
  {
    cout<<"CY";
  } else
  {
    cout<<"SK";
  }
  return 0;
}