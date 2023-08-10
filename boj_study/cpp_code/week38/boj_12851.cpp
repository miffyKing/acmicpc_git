#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int visited[100005] = {0, };

int main()
{

  int n,k;
  int first_flag = 0;
  int ans_cnt = 0;
  int ans_time = 0;
  cin>>n>>k;

  queue<pair<int, int> > q;
  q.push(make_pair(n, 0));
  visited[n] = 1;
  while(!q.empty())
  {
    pair<int, int> cur = q.front();
    q.pop();
    
    visited[cur.first] = 1;

    if (cur.first == k)
    {
      if(first_flag == 0)
      {
        ans_time = cur.second;
        first_flag = 1;
        ans_cnt = 1;
      }
      else
      {
        if (cur.second == ans_time)
        {
          ans_cnt++;
        }
      }
    }
    
    if (cur.first - 1 >= 0 && cur.first - 1 <= 100000)
    {
      if (visited[cur.first - 1] == 0)
      {
        visited[cur.first - 1] = 1;
        q.push(make_pair(cur.first - 1, cur.second + 1));
        visited[cur.first - 1] = 0;

      }
    }
    
    if (cur.first + 1 >= 0 && cur.first + 1 <= 100000)
    {
      if (visited[cur.first + 1] == 0)
      {
        visited[cur.first + 1] = 1;
        q.push(make_pair(cur.first + 1, cur.second + 1));
      visited[cur.first + 1] = 0;
      }
    }
    
    if (cur.first * 2 >= 0 && cur.first * 2 <= 100000)
    {
      if (visited[cur.first * 2] == 0)
      {
        visited[cur.first * 2] = 1;
        q.push(make_pair(cur.first * 2, cur.second + 1));
      visited[cur.first * 2] = 0;
      }
    }
  }


  cout<<ans_time<<"\n";
  cout<<ans_cnt<<"\n";
  return 0;
}