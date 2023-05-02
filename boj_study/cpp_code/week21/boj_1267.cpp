#include <iostream>
#include <vector>

using namespace std;
int main()
{
  int n;
  vector<int> arr;
  cin >> n;
  int y = 0;
  int m = 0;
  for (int i = 0; i < n; i++)
  {
    int tmp;
    cin >> tmp;
    y += (10 * ((tmp / 30) + 1));
    m += (15 * ((tmp / 60) + 1));
  }

  if (y < m)
  {
    cout << "Y " << y << "\n";
  }
  else if (y > m)
  {
    cout << "M " << m << "\n";
  }
  else
  {
    cout << "Y M " << y << "\n";
  }

  return 0;
}