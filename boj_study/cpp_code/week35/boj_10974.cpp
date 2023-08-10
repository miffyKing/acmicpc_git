#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int n;
int flag = 0;
vector<int> givens;
int isused[10002];
int pack[10002];

void func(int cnt)
{
  if (cnt == n) // 4개 다 채웠으면
  {
    // cout << "\n===================================\n";
    for (int i = 0; i < n; i++)
    {
      cout << pack[i] << " ";
    }
    cout << "\n";

  }

  for (int i = 1; i <= n; i++)
  {
    if (isused[i] == 0)
    {
      isused[i] = 1;
      pack[cnt] = i;
      func(cnt + 1);
      pack[cnt] = 0;
      isused[i] = 0;
    }
  }
}

int main()
{
  cin >> n;
  
  func(0);
  if (flag == 1)
    cout<<-1<<"\n";
  return 0;
}