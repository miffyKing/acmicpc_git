#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int n,k;
  cin>>n>>k;
  string input;
  cin>>input;

  int arr[20002] = {0,};
  int cnt = 0;
  for (int i = 0; i < n; i++)
  {
    bool flag = false;
    if(input[i] == 'P')
    {
      for(int j = -1*k; j <= k; j++)
      {
        if (i + j >= 0 && flag == false && i + j < n)
        {
          if (arr[i+j] == 0 && input[i+j] == 'H')
          {
            arr[i+j] = 1;
            cnt++;
            flag =true;
          }
        }
      }
    }
  }
  cout<<cnt<<"\n";
  return 0;
}