#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <utility>
#include <algorithm>
#include <math.h>

using namespace std;

int n;
int arr[27][27];
int visited[27][27];
vector<int> anslst;
int dir_x[4] = {-1, 0, 1, 0};
int dir_y[4] = {0, 1, 0, -1};
int saedae = 0;

void dfs(int row, int col)
{
  saedae++;
  visited[row][col] =1;

  for (int i = 0; i < 4; i++)
  {
    int new_x = dir_x[i] + row;
    int new_y = dir_y[i] + col;
    if(new_x < 0 || new_x >= n || new_y < 0 || new_y >= n) continue;
    if (visited[new_x][new_y] == 0 && arr[new_x][new_y] == 1)
    {
      dfs(new_x, new_y);
    }
  } 
}

int main()
{
  cin>>n;
  for (int i = 0; i < n; i++)
  {
    string str;
    cin>>str;
    for (int j = 0; j <n; j++)
    {
      int a = str[j] - '0';
      arr[i][j] = a;
    }
  }

  int danji = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (arr[i][j] == 1 && visited[i][j] == 0)
      {
        danji++;
        dfs(i, j);
        //cout<<cnt<<"\n";
        anslst.push_back(saedae);
        saedae = 0;
      }
    }
  }
  cout<<danji<<"\n";
  sort(anslst.begin(), anslst.end());
  for (int i = 0; i < (int)anslst.size(); i++)
  {
    cout<<anslst[i]<< "\n";
  }
  return 0;
}