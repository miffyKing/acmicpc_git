#include <iostream>
#include <queue>
using namespace std;

bool visited[100001];
int N, K;
void bfs(int subin, int bro)
{
	visited[subin] = true;
	queue<pair<int, int>> Q;
	Q.push({ subin, 0 });
	while (!Q.empty())
	{
		int loc = Q.front().first;
		int cnt = Q.front().second;
		if (loc == bro)
		{
			cout << cnt << endl;
			return;
		}

		if (loc * 2 <= 100000 && visited[loc * 2] == false)
		{
			visited[loc * 2] = true;
			Q.push({ loc * 2, cnt });
		}
        if (loc - 1 >= 0 && visited[loc - 1] == false)
		{
			visited[loc - 1] = true;
			Q.push({ loc - 1, cnt + 1 });
		}
        if (loc + 1 <= 100000 && visited[loc + 1] == false)
		{
			visited[loc + 1] = true;
			Q.push({ loc + 1, cnt + 1 });
		}
        
		Q.pop();
	}
}

int main()
{
	cin >> N >> K;
	bfs(N, K);
	return 0;
}