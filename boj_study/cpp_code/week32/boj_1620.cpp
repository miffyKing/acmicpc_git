#include <iostream>
#include <map>
#include <cstring>

using namespace std;

int main()
{
  cin.tie(0);

  int n, m;
  map<string, string> names;
  map<string, string> numbers;

  string tmp;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
  {
    cin >> tmp;
    names.insert({tmp, to_string(i)});
    numbers.insert({to_string(i), tmp});
  }
  for (int i = 0; i < m; i++)
  {
    string tmp;
    cin >> tmp;

    if (names.find(tmp) != names.end())
    {
      auto found = names.find(tmp);
      cout << found->second << '\n';
    }
    else
    {
      auto found = numbers.find(tmp);
      cout << found->second << '\n';
    }
  }
  return 0;
}
