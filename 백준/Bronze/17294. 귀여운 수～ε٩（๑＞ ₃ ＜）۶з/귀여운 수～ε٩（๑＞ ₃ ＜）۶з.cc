#include <iostream>
#include <string.h>

using namespace std;

int main()
{
  string a;
  cin>>a;
  int diff2 = a[1] - a[0];
  for (int i = 2; i < a.length(); i++)
  {
    if (a[i] - a[i-1] != diff2)
    {
      cout<<"흥칫뿡!! <(￣ ﹌ ￣)>\n";
      return 0;
    }
  }
  
  cout<<"◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!";

  
  return 0;
}