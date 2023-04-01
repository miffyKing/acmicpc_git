#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
  int l,a,b,c,d;

  cin >>l>>a>>b>>c>>d;
  int korean = a / c;
  int math = b/d;
  int korean_left = a%c;
  int mathleft = b%d;
  int k_total, m_total;
  if(korean_left > 0)
  {
    k_total = korean+1;
  } else {
    k_total = korean;
  }
  if(mathleft > 0)
  {
    m_total = math+1;
  } else {
    m_total = math;
  }
  int maxval = max(m_total, k_total);
   
  cout<<l-maxval<<"\n";
  return 0;
}