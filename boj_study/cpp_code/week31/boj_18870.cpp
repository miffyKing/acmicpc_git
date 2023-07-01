#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <utility>
using namespace std;

map<int, int> ranks;

int main()
{
  int n, tmp;
  vector<int> input;
  vector<int> input2;
  // vector<pair<int, int >> sorted;
  vector<int> ans;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> tmp;
    input.push_back(tmp);
    input2.push_back(tmp);
  }
  sort(input2.begin(), input2.end());
  input2.erase(unique(input2.begin(), input2.end()), input2.end());
  for (int i = 0; i < n; i++)
  {
    cout<< lower_bound(input2.begin(), input2.end(), input[i]) - input2.begin() << " ";
  }
  return 0;
}

//https://sangwoo0727.github.io/c++/Cplus-unique/