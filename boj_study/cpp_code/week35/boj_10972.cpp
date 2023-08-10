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

bool func()
{
  int i = n-1;
  while(i > 0 && givens[i-1] >= givens[i]) i -=1;

  if (i <= 0) return false;
  int j = n-1;
  while(givens[j] <= givens[i-1]) j -= 1;
  swap(givens[i-1], givens[j]);
  j = n-1;
  while(i < j)
  {
    swap(givens[i], givens[j]);
    i +=1;
    j -=1;
  }
  return true;
}

int main()
{
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int tmp;
    cin >> tmp;
    givens.push_back(tmp);
  }

  if (func())
  {
    for (int i = 0; i < n; i++)
    {
      cout<<givens[i] << " ";
    }
    cout<<"\n";
  }
  else 
    cout<<"-1";
  return 0;
}