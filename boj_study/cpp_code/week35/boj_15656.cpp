#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,m;
int isused[10];
int arr[10];
vector<int> lst;

void func(int k)
{
  if (k == m)
  {
    for (int i = 0; i < m; i++)
    {
      cout<<arr[i] << " ";
    }
    cout<<"\n";
    return;
  }
  for (int i = 0; i < n ; i++)
  {
    
      arr[k] = lst[i];
      func(k+1);
    
  }
  
}

int main()
{
  cin>>n>>m;
  for (int i = 0; i < n; i++)
  {
    int tmp;
    cin>>tmp;
    lst.push_back(tmp);
  }
  sort(lst.begin(), lst.end());
  func(0);

  return 0;
}