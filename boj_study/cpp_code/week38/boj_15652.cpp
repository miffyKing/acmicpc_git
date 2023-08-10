#include <iostream>

using namespace std;

int ans[10];
int n, m;

void func(int num)
{
  if (num == m)
  {
    for (int i = 1; i <= m; i++)
    {
      cout<<ans[i] << " ";
    }
    cout<<"\n";
    return ;
  }

  for (int i = 1; i <= n; i++)
  {
    if (ans[num] <= i)
    {
      ans[num+1] = i;
      func(num+1);
      ans[num+1] = 0;
    }
  }
  
}

int main()
{

  cin >> n >> m;

  func(0);

  return 0;
}