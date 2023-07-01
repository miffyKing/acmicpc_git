#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

map<int,int> counts;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, tmp;
  vector<int> arr1;
  vector<int> answer;

  cin>>n;
  for (int i = 0; i < n; i++)
  {
    cin >> tmp;
    //cout<< "i is " << i << " tmp is " << tmp <<"\n"; 
    if (counts.find(tmp) == counts.end())
    {
      counts.insert(make_pair(tmp, 1));
      arr1.push_back(tmp);
    }
    else 
      counts.find(tmp)->second++;
    
  }
  sort(arr1.begin(), arr1.end());

  cin >> m;

  for (int i = 0; i < m; i++)
  {
    cin >> tmp;
    int ans = 0;
    int from = 0;
    int to = arr1.size()-1;
    int found = 0;

    while (from <= to)
    {
      int mid = (from + to) / 2;

      if (tmp == arr1[mid])
      {
        found = 1;
        // ans = counts.find(mid)->second;
        ans = counts[arr1[mid]];
        break;
      }
      if (tmp > arr1[mid])
        from = mid + 1;
      
      else if (tmp < arr1[mid])
        to = mid - 1;
      
    }
    if (found == 0) 
      answer.push_back(0);
    else 
      answer.push_back(ans);
  }
  for (int i = 0; i < m; i++)
    cout << answer[i] << " ";
  cout << "\n";
  return 0;
}