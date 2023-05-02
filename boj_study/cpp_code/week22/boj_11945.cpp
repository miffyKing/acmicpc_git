#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int n, m;
  cin>>n>>m;
  vector<string> arr;
  for (int i = 0; i < n; i++)
  {
    string tmp;
    cin>>tmp;
    arr.push_back(tmp);
  }
  for(int i = 0; i < n; i++)
  {
    for (int j = m-1; j >= 0; j--)
    {
      cout<<arr[i][j];
    }
    cout<<"\n";
  }

  
  return 0;
}