#include <iostream>
#include <vector>

using namespace std;

int visited[1002];
vector<int> relation[1002];

void dfs(int idx)
{
  visited[idx] = 1;
  for(int i = 0; i < (int)relation[idx].size(); i++)
  {
    if(visited[relation[idx][i]] == 0)
    {
      dfs(relation[idx][i]);
    }
  }

}

int main()
{
  int n, m,   a, b;
  cin>>n>>m;

  for(int i = 0; i < m ; i++)
  {
    cin>>a>>b;
    relation[a].push_back(b);
    relation[b].push_back(a);
  }

  int cnt = 0;

  for (int i = 1; i <= n; i++)
  {
    if(visited[i] == 0)
    {
     //cout<<"i is  " << i << "\n";
      cnt++;
      dfs(i);
    }
  }
  cout<<cnt<<"\n";
  return 0;
}