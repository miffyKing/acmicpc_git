#include <iostream>
#include <vector>
#include <stack>
using namespace std;
#define ffor(i, x) for (long long (i) = 0; (i) < (x) ; (i)++) // :별:️ 0부터 x까지 for-loop
#define ccc(x) long long (x); cin >> (x); // :별:️ int 변수 만들고 그걸로 stdin 인풋 하나 받기
#define cob(x) cout << x << ' '; // :별:️ 변수 출력하고 스페이스바
#define ii pair<long long, long long> // :별:️ 보통 vector랑 많이 쓴다

vector<ii> v;
stack<ii> s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ccc(N);
   
    ffor(i,N){
        ii x;
        cin >> x.first;
        x.second = i+1;
        v.push_back(x);
    }
//    for(int i = 0; i< N; i++)
//    {
//        cout << v[i].second << ' ';
//    }
  //  cout<<'\n';
    int i = 0;
    while (i < N){
        if (s.empty()){
            s.push(v[i]);
            i++;
            cout << '0' << ' ';
          
        }
        else if (v[i].first <= s.top().first){
            cout << s.top().second << ' ';
            s.push(v[i]);
            i++;
        }
        else if (v[i].first > s.top().first){
            s.pop();
        }
    }
    return (0);
}
