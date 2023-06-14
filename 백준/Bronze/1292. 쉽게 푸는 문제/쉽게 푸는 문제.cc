#include <iostream>
#include <vector>
using namespace std;

// int arr[1002];
vector<int> arr;
void get_arr()
{
  for(int i = 1; i <= 50; i++)
  {
    for(int j = 1; j <= i; j++)
    {
      arr.push_back(i);
    }
  }
}
int main()
{
  int a,b;
  get_arr();
  cin>>a>>b;
  int sum = 0;
  for(int i = a-1; i <=b-1; i++)
  {
    sum += arr[i];
  }
  cout<<sum<<"\n";
  return 0;
}