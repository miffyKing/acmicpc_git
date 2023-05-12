#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[10];
int main()
{

  string n;
  cin >> n;
  for (int i = 0; i < n.length(); i++)
  {
    if (n[i] - '0' == 9)
    {
      arr[6]++;
      continue;
    }
    arr[n[i] - '0']++;
  }

  int sixnine;
  if (arr[6] % 2 == 1)
  {
    sixnine = (arr[6] / 2) + 1;
  }
  else
  {
    sixnine = (arr[6] / 2);
  }
  arr[6] = 0;
  sort(arr, arr + 10);
  int elseval = arr[9];

  if (sixnine > elseval)
  {
    cout << sixnine;
  }
  else
  {
    cout << elseval;
  }
  return 0;
}