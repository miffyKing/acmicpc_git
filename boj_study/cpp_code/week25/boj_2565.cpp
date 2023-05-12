#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <utility>

using namespace std;
int dp[102];
vector<pair<int, int> > lines;
int main()
{
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int tmp1, tmp2;
    cin >> tmp1 >> tmp2;
    lines.push_back(make_pair(tmp1, tmp2));
  }

  sort(lines.begin(), lines.end());

  vector<pair<int, int> > tmp;
  tmp.push_back(make_pair(lines[0].first, lines[0].second));

  
  for (int i = 0; i < n; i++)
  {
    dp[i] = 1;
    for(int j = 0; j < i; j++)
    {
      if (lines[i].second > lines[j].second)
      {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
  }
  sort(dp+0, dp+n);
  cout<<n-dp[n-1]<<"\n";

  return 0;
}