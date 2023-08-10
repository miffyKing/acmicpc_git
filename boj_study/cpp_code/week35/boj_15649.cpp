#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int isused[10];
int arr[10];
int n,m;

void func(int num)
{
  if (num == m)
  {
    for (int i = 0; i < m; i++)
    {
      cout<< arr[i] << "\n";
    }
    return ;
  }
  for (int i = 1; i <= n; i++)
  {
    if (isused[i] != 0)
      continue;
    isused[i] = 1;
    arr[num] = i;
    func(num+1);
    isused[i] = 0;
  }

}
int main()
{
  cin>>n>>m;
  func(0);
  return 0;
}