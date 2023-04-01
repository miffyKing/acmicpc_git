#include <iostream>

using namespace std;

int main()
{
  int n;
  cin>>n;
  cin.ignore();
  for (int i = 0; i < n; i++)
  {
    string tmp;
    getline(cin, tmp);
    for (int i = 0; i < tmp.length(); i++)
    {
      if (tmp[i] >= 'A' && tmp[i] <= 'Z')
      {
        tmp[i] =  tmp[i] - 'A'+'a';
      }
    }
    cout<<tmp<<"\n";
  }

  return 0;
}