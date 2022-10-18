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

#define ffor(i, x) for (int (i) = 0; (i) < (x) ; ++(i))
#define fffor(i, x) for (int (i) = 1; (i) <= (x) ; ++(i))
#define cc(x) cin >> (x); // ⭐️ stdin 인풋 하나 받기
#define ccc(x) int (x); cin >> (x); // ⭐️ int 변수 만들고 그걸로 stdin 인풋 하나 받기
#define coo(x) cout << x << '\n'; // ⭐️ 변수 출력하고 줄바꿈
#define cob(x) cout << x << ' '; // ⭐️ 변수 출력하고 스페이스바
#define ii pair<int, int> // ⭐️ 보통 vector랑 많이 쓴다
#define ll long long
int dx[] = {1, 0, -1, 0}; // 동 남 서 북 // ⭐️ DFS, BFS 문제 풀 때 꼭 씀
int dy[] = {0, 1, 0, -1};
int INF = 1e9 + 7;

int solution(int num, vector<int> v)
{
    int   start = 0;
    int end = (int)v.size() - 1;
    int mid;
    vector<int>::iterator cur = v.begin();
    int sum = 0;
    cout<<">>>>\n";
    while(start <= end){
        mid = (start + end) / 2;
        cur += mid;
        cout << "check:: start "<< start<< " mid " << mid << "end " << end<<'\n';;
        if(v[mid] == num)
        {
            sum++;
            v.erase(cur);
            v.shrink_to_fit();
        }
        else if(v[mid] < num)
        {
            start = mid + 1;
        }
        else if(v[mid] > num)
        {
            end = mid - 1;
        }
    }
    cout<<">>>>\n";
    return (sum);
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);

   ccc(N);
   vector<int> a;
   while (N--)
   {
       //int tmp;
       ccc(tmp);
       a.push_back(tmp);
   }
   ccc(M);
   int M_mem = M;
   vector<ii> b;
    cout<<"!!!!!\n";
   while (M--){
      ii tmp;
      cin >> tmp.first;
      b.push_back(tmp);
     //  cout<<tmp.first<<'\n';
   }
    
     cout<<"!!!!!\n";
   sort(a.begin(),a.end());
    
     cout<<"!!!!!\n";
    
   for (int i = 0; i < M_mem; i++){
      b[i].second = solution(b[i].first, a);
      cob(b[i].second);
   }
   return (0);
}
