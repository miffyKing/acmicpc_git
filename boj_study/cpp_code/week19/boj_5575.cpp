#include <iostream>

using namespace std;

int main()
{
  int a,b,c,d,e,f;
  for (int i = 0; i < 3; i++)
  {
    cin>>a>>b>>c>>d>>e>>f;
    int start = a*60*60 + b*60 + c;
    int end = d *60*60 + e*60 + f;
    int diff = end - start;
    int h = diff / 3600;
    int m = (diff % 3600)/60;
    int s = (diff % 3600)%60;
    cout << h << ' ' << m << ' ' << s<<"\n";
  }
  return 0;
}