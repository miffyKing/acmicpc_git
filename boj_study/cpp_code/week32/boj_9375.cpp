#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
  int n;
  string tmp1, tmp2;

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int m;
    map<string, int> list;
    cin >> m;
    for (int j = 0; j < m; j++)
    {
      cin >> tmp1 >> tmp2;
      if (list.find(tmp2) != list.end())
      {
        int num = list[tmp2];
        num++;
        list.erase(tmp2);
        list.insert({tmp2, num});
      }
      else
        list.insert({tmp2, 1});
    }
    vector<int> numbers;
    for (auto iter = list.begin(); iter != list.end(); iter++)
    {
      numbers.push_back(iter->second);
    }
    long long ans = 1;
    for (int i = 0; i < numbers.size(); i++)
      `
      {
        ans *= (numbers[i] + 1);
      }
    ans--;
    cout << ans << '\n';
  }

  return 0;
}
