#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <list>
using namespace std;
#define ffor(i, x) for (int (i) = 0; (i) < (x) ; (i)++) // :별:️ 0부터 x까지 for-loop
#define fffor(i, x) for (int (i) = 1; (i) <= (x) ; ++(i)) // :별:️ 1부터 x까지 for-loop
#define cc(x) cin >> (x); // :별:️ stdin 인풋 하나 받기
#define ccc(x) int (x); cin >> (x); // :별:️ int 변수 만들고 그걸로 stdin 인풋 하나 받기
#define coo(x) cout << x << '\n'; // :별:️ 변수 출력하고 줄바꿈
#define cob(x) cout << x << ' '; // :별:️ 변수 출력하고 스페이스바
#define ii pair<int, int> // :별:️ 보통 vector랑 많이 쓴다
#define ll long long // :별:️ 매번 long long 치고 있으면 현기증이 옴
int dx[] = {1, 0, -1, 0}; // 동 남 서 북 // :별:️ DFS, BFS 문제 풀 때 꼭 씀
int dy[] = {0, 1, 0, -1}; // :별:️ 이렇게 안하고 2x4 배열로 만들어 쓰는 사람들도 있는 것 같다
int INF = 1e9 + 7; // :별:️ 의외로 자주 쓰는 수. 자주 쓰고 말고는 문제를 풀면서 생각해보면 될 문제
int n,m;
int map[101][101];
int BFS(int row, int col){
    int sum = 1;
    queue<pair<int, int> > q;
    q.push(make_pair(row,col));
    map[row][col] = 0;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0 <= nx && nx <= n &&
                0 <= ny && ny <= m &&
                map[nx][ny] == 1){
                    q.push(make_pair(nx,ny));
                    map[nx][ny] = 0;
                    sum++;
                }
        }
    }
    return sum;
}
int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        string tmp;
        cin>>tmp;
        for (int j = 0; j < m ; j++){
            map[i][j] = tmp[j] - '0';
        }
    }
    cout<<'\n';
    for (int i = 0; i < n; i++)
    {
        for(int j= 0; j < m; j++)
        {
            cout<<map[i][j];
        }
        cout<<'\n';
    }
    
    
    int areaSize = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++){
            if (map[i][j] == 1){
                int tmp = BFS(i, j);
                areaSize = max(areaSize, tmp);
            }
        }
    }
    cout << areaSize;
    return (0);
}
