#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
  int n;
  
  cin>>n;
  cin.ignore();
  for (int i= 0; i < n; i++)
  {
    char tmp[52];
    cin.getline(tmp, 100, '\n');
    cout<<i+1 << ". " << tmp<<"\n";
  }

  return 0;
}