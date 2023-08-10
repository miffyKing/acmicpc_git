#include <iostream>

#include <queue>

using namespace std;

int n,k;
bool visited[100001];

int main()
{
  cin>>n>>k;

  queue<pair<int,int> > q;

  q.push(make_pair(n, 0));
  visited[n] = 1;
  while(!q.empty())
  {
    pair<int,int> cur = q.front();
    q.pop();

    if(cur.first == k)
    {
      //cout<<"!!!!!!!!!!!!!   ";
      cout<<cur.second<<"\n";
      return 0;
    }

    if (cur.first * 2 <= 100000 && visited[cur.first * 2] == 0)
    {
      //cout<<"3 \n";
      visited[cur.first * 2] = 1;
      q.push(make_pair(cur.first * 2, cur.second));
    }
    if (cur.first - 1 >= 0 && visited[cur.first- 1] == 0)
    {
      //cout<<"1 \n";
      visited[cur.first - 1] = 1;
      q.push(make_pair(cur.first - 1, cur.second + 1));
    }
    if (cur.first + 1 <= 100000 && visited[cur.first + 1] == 0)
    {
      //cout<<"2 \n";
      visited[cur.first + 1] = 1;
      q.push(make_pair(cur.first + 1, cur.second + 1));
    }
    

  } 

  return 0;
}