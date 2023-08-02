#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

int isvisited[2002];
vector<int> table[2002];
bool possible = false;

void check_relation(int start, int depth)
{
  
  //cout<<"start pos is    " << start << "\n";
  if(depth > 4)
  {
    possible = true;
    return;
  }
  isvisited[start] = 1;
  for(int i = 0; i < (int)table[start].size(); i++)
  {

    if(isvisited[table[start][i]] != 1 && possible == false)
    {
      check_relation(table[start][i], depth+1);
    }
  }
  isvisited[start] = 0;
  return;
}
int main()
{
  int n,m;

  cin>>n>>m;

  for(int i = 0; i < m; i++)
  {
    int a,b;
    cin>>a>>b;
    table[a].push_back(b);
    table[b].push_back(a);
  }  

  // for(int i = 0; i < n; i++)
  // {
  //   for(int j = 0; j < table[i].size(); j++)
  //   {
  //     cout<<table[i][j]<<" ";
  //   }
  //   cout<<"\n";
  // }
  for (int i = 0; i < n; i++)
  {
    check_relation(i, 1);
    if(possible == true)
    {
      cout<<1;
      return 0;
    }
  }
  cout<<0;

  return 0;
}