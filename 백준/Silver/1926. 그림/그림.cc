#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

int dir_x[4] = {-1, 0, 1, 0};
int dir_y[4] = {0, -1, 0, 1};

 int n,m;
int isvisited[502][502];
int table[502][502];
int max_val = -1;

void dfs(int x, int y)
{
  queue< pair<int, int> > q;
  
  int cnt = 1;
  q.push(make_pair(x,y));
  isvisited[x][y] = 1;

  while (!q.empty())
  {
    int cur_x = q.front().first;
    int cur_y = q.front().second;
    q.pop();

    for (int i = 0; i <4; i++)
    {
      int new_x = cur_x + dir_x[i];
      int new_y = cur_y + dir_y[i];

      if(new_x < 1 || new_x > n || new_y < 1 || new_y > m) continue;
      if (isvisited[new_x][new_y] == 0 && table[new_x][new_y] == 1)
      {
        isvisited[new_x][new_y] = 1;
        q.push(make_pair(new_x, new_y));
        cnt++;
      }
    }
  }

  max_val = max(max_val, cnt);
}
int main()
{
 

  cin>>n>>m;
  

  for(int i = 1; i<= n; i++)
  {
    for (int j  =1; j<= m; j++)
    {
      cin>>table[i][j];
    }
  }

  int pic_num = 0;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j<= m; j++)
    {
      if (table[i][j] == 1 && isvisited[i][j] == 0)   //방문안했을 때 dfs 실행해야해
      {
        //cout<<"picture begins here : (" << i << " , " << j << ")\n";
        pic_num++;
        dfs(i,j);
      }
    }
  }
  if (pic_num == 0)
  {
    cout<< 0 << "\n" << 0 <<"\n";
  } else 
  {
  cout<<pic_num <<"\n";
  cout<<max_val<<"\n";
  }
  return 0;
}
