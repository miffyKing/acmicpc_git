#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int v;
vector< pair<int,int> > trees[100002];
int visited[100002];
int max_dist = -1;
int maxvalue = -1;

void dfs(int i, int dist)
{
  if (visited[i] == 1)
    return;
  if (max_dist < dist)
  {
    max_dist = dist;
    maxvalue = i;
  }

  visited[i] = 1;
  for (int j = 0; j < (int)trees[i].size(); j++)
  {
    dfs(trees[i][j].first, trees[i][j].second + dist);
  }
}

int main()
{
  cin>>v;

  for (int i = 0; i < v; i++)
  {
    int num, n1, n2;
    cin>>num;
    cin>>n1;
    while(n1 != -1)
    {
      cin>>n2;
      trees[num].push_back(make_pair(n1,n2));
      trees[n1].push_back(make_pair(num,n2));
      cin>>n1;
    }
  }

  // for (int i = 1; i <= v; i++)
  // {
  //   for (int j = 0; j < trees[i].size(); j++)
  //   {
  //     cout<<trees[i][j].first << " ";
  //   }cout<<"\n";
  // }

  dfs(1, 0);
 // cout<<maxvalue<<"\n";
  memset(visited, 0, sizeof(int) * 100001);

  dfs(maxvalue, 0);
  cout<<max_dist<<"\n";

  return 0;
}