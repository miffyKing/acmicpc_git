#include <iostream>

using namespace std;

int arr[50002] = {0,};
int main()
{
  int n;
  cin>>n;
  
  for (int i = 1; i <= n; i++)
  {
    arr[i] = arr[i-1] + 1;
    for (int j = 1; j*j <= i; j++) 
    {
      arr[i] = min(arr[i], arr[i-(j*j)] + 1);
    }
  }
  cout<<arr[n]<<"\n";
  return 0;
}