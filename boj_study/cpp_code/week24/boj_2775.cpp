#include <iostream>

using namespace std;

int arr[16][16];

int main()
{
  int t;
  int k, n;

  arr[0][0] = 1;
  arr[1][0] = 0;
  for (int i = 1; i <= 15; i++)
  {
    arr[0][i] = i;
  }
  arr[1][0] = 0;

  for (int i = 1; i <= 15; i++)
  {
    for (int j = 1; j <= 15; j++)
    {
      arr[i][j] = arr[i][j - 1] + arr[i - 1][j];
     }
  }

  cin >> t;
  for (int idx = 0; idx < t; idx++)
  {
    cin >> k >> n;
    cout << arr[k][n]<<"\n";
  }

  return 0;
}