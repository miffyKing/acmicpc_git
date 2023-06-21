#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main()
{
  int n, m;
  vector<int> arr1;
  vector<int> arr2;
  int tmp;

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> tmp;
    arr1.push_back(tmp);
  }
  cin >> m;
  for (int i = 0; i < m; i++)
  {
    cin >> tmp;
    arr2.push_back(tmp);
  }

  sort(arr1.begin(), arr1.end());
  
  vector<int> answer;
  for (int i = 0; i < m; i++)
  {
     int from, to;
    int target = arr2[i];
    from = 0;
    to = n - 1;

    // 이분 탐색으로 수를 찾는 부분
    bool found = false;  // 수를 찾았는지 여부를 저장할 변수 추가
    while (from <= to)  // 조건 변경: from <= to로 수정
    {
      int mid = (from + to) / 2;
      if (arr1[mid] == target)  // 수를 찾은 경우
      {
        found = true;
        break;
      }
      else if (target < arr1[mid])  // 중간값보다 작은 경우
      {
        to = mid - 1;
      }
      else  // 중간값보다 큰 경우
      {
        from = mid + 1;
      }
    }

    if (found)
      answer.push_back(1);
    else
      answer.push_back(0);
  }

  for (int i = 0; i < m; i++)
  {
    cout << answer[i] << "\n";
  }
}