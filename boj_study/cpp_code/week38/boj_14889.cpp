#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;


int n;
int graph[22][22];
bool visited[22];
int answer = 987654321;

void dfs(int x, int pos)
{
  if (x == n/2)
  {
    int start = 0;
    int link = 0;
    for (int i = 1; i <=n; i++)
    {
      for (int j = 1; j<=n; j++)
      {
        if (visited[i] == true && visited[j] == true) start += graph[i][j];
        if (visited[i] == false && visited[j] == false) link += graph[i][j];
        
      }
    }
    int tmp = abs(start - link);
    if (answer > tmp) answer = tmp;
    return;
  }

  for (int i = pos; i < n; i++)
  {
    visited[i] = true;
    dfs(x+1, i+1);
    visited[i] = false;
  }
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> graph[i][j];
		}
	}

	dfs(0, 1);
	cout << answer;
	return 0;
}