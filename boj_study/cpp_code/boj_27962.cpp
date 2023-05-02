#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
  int n;
  string a;

  cin>>n;
  cin>>a;

  int end = a[n-1];
  int start = 0;
  vector<int> startpoint;
  for (start = 0; start < n; start++)
  {
    if (a[start] == end)
    {
      startpoint.push_back(start);
    }
  } 
  if (startpoint.size() == 1)
  {
    cout<<"NO\n";
    return 0;
  }
  for (int idx = 0; idx < startpoint.size(); idx++)
  {
      int start = startpoint[idx];
      int cnt = 0;
      for (int i = 0; i < start; i++)
      {
        if (a[i] != a[n-1-start])
        {
          cnt++;
        }
      }
      if (cnt >1 )
      {
        //cout<<"NO\n";
        //continue;
      }
      else if (cnt == 0)
      {
      // cout<<"NO\n";
      //continue;
      } else{
      cout<<"YES\n";
      }
    //  return 0;
  }
  cout<<"NO\n";

}