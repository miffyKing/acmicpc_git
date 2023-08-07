#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

#define MAX 502
long long int INF = 987654321;
using namespace std;

//int n, m, Start, End;
int dist[MAX][MAX];
//vector<pair<int, int>> adj[MAX];
//long long int negacount = 0;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int i, j;
    int N, M;
    cin >> N >> M;

    for (int i = 1;i <= N;i++)
    {
        for (int j = 1;j <= N;j++)
        {
            if (i == j)continue;
            dist[i][j] = INF;
        } //배열 초기화
    }

    for (i = 0; i < M;i++)
    {
        int a, b;
        cin >> a >> b;
        dist[a][b] = min(dist[a][b], 1);
        dist[b][a] = min(dist[b][a], 1);
    }

    for (int k = 1;k <= N;k++)
    {
        for (int i = 1;i <= N;i++)
        {
            for (int j = 1;j <= N;j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }

    }
    int mini = INF;
    
    int sum[MAX] = { 0 };
    for (i = 1;i <= N;i++)
    {
        for (j = 1;j <= N;j++)
        {
          //  printf("%d ", dist[i][j]);
            sum[i] = sum[i] + dist[i][j];
        }
      //  printf("\n");
    }

    for (i =1;i <= N;i++)
    {
       // printf("%d\n", sum[i]);
        mini = min(mini, sum[i]);
    }
    for (i = 1;i <= N;i++)
    {
        if (mini == sum[i])
        {
            printf("%d\n", i);
            break;
        }

    }


    
    return 0;
}
