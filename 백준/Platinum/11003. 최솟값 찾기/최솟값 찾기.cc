#include <iostream>
#include <deque>
#include <vector>
#include <utility>

using namespace std;

// 5000000개 입력에 대한 크기 D부분문자열 찾고, 그 중 최솟값 찾기
// n x nlogn(정렬)  시간초과 난당
// 슬라이딩 윈도우 사용

int n, l;
deque<pair<int,int> > dq;
int A[5000001];
vector<pair<int, int> > node;

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  cin>>n>>l;
  for (int i = 0; i < n; i++)
  {
    cin>>A[i];
    while(!dq.empty() && dq.back().second > A[i])  //디큐 젤 뒤에 수를 현재 입력값과 비교해 더 값이 크면 팝해버린다.
      dq.pop_back();
    dq.push_back(make_pair(i, A[i]));

    if (!dq.empty() && ( i - dq.front().first) >= l)
      dq.pop_front();
    cout<<dq.front().second<<" ";
  }


  

}