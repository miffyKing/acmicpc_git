#include <iostream>

using namespace std;

int n,m;
int isused[10];
int arr[10];

void func(int k)
{
  if (k == m)
  {
    for (int i = 0; i < m; i++)
      cout<<arr[i]<<" ";
    cout<<"\n";
    return;
  }
  
  for (int i = 1; i <= n; i++)
  {
    arr[k] = i;
    func(k+1);
  }

}

int main()
{
  cin>>n>>m;

  func(0);
  return 0;
} 