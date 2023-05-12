#include <iostream>

using namespace std;


int arr[31][31] = {0,};
int main()
{
  int tc;
  for (int i = 1; i <= 30; i++)
  {
    arr[i][0] = 1;
    arr[i][i] = 1;
  }
  for (int i = 1; i <= 30; i++)
  {
    for (int j = 1; j <= 30; j++)
    {
      if (i!=j && (i!=1||j!=1))
      {
        arr[i][j] = arr[i-1][j]+arr[i-1][j-1];
      }
    }
  }
  
  cin>>tc;

  for (int i = 0; i < tc; i++)
  {
    int n,m;
    cin>>n>>m;
    cout<<arr[m][n]<<"\n";
  }
  return 0;
}