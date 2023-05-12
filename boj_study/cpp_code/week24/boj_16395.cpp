#include <iostream>

using namespace std;

int arr[32][32];

int main()
{

  arr[1][1] = 1;
  arr[2][1] = 1;
  arr[2][2] = 1;
  for (int i = 3; i <= 30; i++)
  {
    arr[i][1] = 1;
    arr[i][i] = 1;
  }
  for (int i = 3; i <= 30; i++)
  {
    for (int j = 2; j < i; j++)
    {
      arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
    }
  }

  int n, k;

  cin >> n >> k;
  cout << arr[n][k];

  return 0;
}