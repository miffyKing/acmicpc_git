#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <map>
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
stack<pair<int,int>> s;
vector<pair<int,int>> ans;
int arr[10000010];

bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
    return (a.second < b.second);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ccc(N)
    ffor(i, N)
        cc(arr[i])
    ffor(i, N)
    {
        int cnt = 0;
        while (!s.empty() && s.top().first < arr[i])
        {
            ans.push_back({arr[i], s.top().second});
            s.pop();
            cnt++;
        }

        if (i == N - 1)
            ans.push_back({-1, i});
        s.push({arr[i],i});
    }
    while(s.empty() != 1)
    {
        ans.push_back({-1, s.top().second});
        s.pop();
    }
    sort(ans.begin(), ans.end(), sortbysec);
    for(int i = 0; i< N; i++)
        cout<< ans[i].first << ' ';
    cout<<'\n';
    return (0);
}
