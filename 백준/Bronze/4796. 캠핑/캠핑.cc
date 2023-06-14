#include <iostream>

using namespace std;

int main()
{
  int l,p,v;
  int idx= 1;
  while(1)
  {
    cin>>l>>p>>v;
    if (l == 0 && p == 0 && v == 0)
      break;
    int mok = v / p;
    int nam = v % p;
    if (nam > l)
      nam = l;
    cout<< "Case " << idx << ": " << mok*l + nam <<"\n"; 
    idx++;
  }
  return 0;
}
