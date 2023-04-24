#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  string n;
  cin>>n;

  vector<int> number;
  int sum = 0;
  int cnt = 0;
  for (int i = 0; i < n.length(); i++)
  {
    if (n[i] == '0')
    {
      cnt++;
    }

    number.push_back(n[i] - '0');
    sum += (n[i] - '0');
  }
  sort(number.begin(), number.end());

  //cout<<sum<<"\n";
  if (sum % 3 == 0)
  {
    if (cnt != 0)
    {
      for(int i =n.length()-1; i >= 1 ; i--)
      {
        cout<<number[i];
      }cout<<0;
      return 0;
    }
  }
  cout<<-1;
  return 0;
}
