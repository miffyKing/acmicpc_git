#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <string.h>

using namespace std;

int main()
{
  int t;
  
  cin>>t;
  for (int idx = 0; idx < t; idx++)
  {
    int n;    cin>>n;
    int team[100002];

    for (int i = 1; i <= n; i++)
    {
      int tmp; cin>>tmp;
      team[i] = tmp;
    }
    queue<int >q;
    int isvisited[100002];
    memset(isvisited, 0, 100002*sizeof(int));
    for (int i = 1; i <= n; i++)
    {
      cout<<"----------------------\n";
      if (isvisited[i] != 0)
      {
      }
      else
      {
        q.push(i);
        isvisited[i] = 1;  
        while(!q.empty())
        {
          int cur = q.front();
          q.pop();

          int next_pos = team[cur];
          if(next_pos == i)
          {
            break;
          }
          if (isvisited[next_pos] >= 1)
            continue;
          cout<<"nextpos is " << next_pos << " cur is " << cur << "\n";
          isvisited[next_pos]++;
          isvisited[cur]++;
          q.push(next_pos);
      }
      }
      
    }
    int cnt = 0;
    cout<<"!!!! : ";
    for (int i = 1; i <=n; i++)
    {
      if (isvisited[i] <= 1)
      {
        cout<<i << " " ;
        cnt++;

      }
    }
    cout<< "\n" << cnt <<"\n";

  }

  return 0;
}