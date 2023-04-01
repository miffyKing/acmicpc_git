#include <iostream>
#include <algorithm>
using namespace std;


int arr[27] = {0,};

int main()
{
  string a;
  cin>>a;
  for (int i = 0; i < a.length(); i++)
  {
    arr[a[i] - 'a']++;
  }
  for (int i = 0; i < 26; i++)
  {
    cout<<arr[i]<< ' ';
  }
}