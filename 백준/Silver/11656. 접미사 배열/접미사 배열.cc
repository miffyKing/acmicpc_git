#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  string input;
  cin>>input;
  vector<string> suffixs;

  for (int i = input.size() -1 ; i >= 0;  i--)
  {
    suffixs.push_back(input.substr(i));
  }
  sort(suffixs.begin(), suffixs.end());
  for (int i = 0; i < suffixs.size(); i++)
  {
    cout<<suffixs[i] << "\n";
  }
  return 0;
}