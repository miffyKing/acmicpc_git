#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  string a, b;
  cin>>a;
  cin>>b;
  vector<string> lst;
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  lst.push_back(a); 
  lst.push_back(b);

  cout<<lst[0]<<"\n";
  cout<<lst[1]<<"\n";
  sort(lst.begin(), lst.end());
  vector<int> sum;
  int olim = 0;
  int i=0;
  for ( i = 0; i < lst[0].length(); i++)
  {
    cout<<"!!!\n";
    int anum = lst[0][i]- '0';
    int bnum = lst[1][i] - '0';
   // cout<<"!!" << anum << "   "  << bnum<<"\n";
    sum.push_back(olim + (anum+bnum)%10);
    if(anum + bnum >= 10)
    {
      olim = 1;
    }
   // cout<<sum[i];
  } 
  sum.push_back(lst[1][i] - '0' + olim) ;

  for (i = lst[0].length(); i < lst[1].length(); i++)
  {
    sum.push_back(lst[1][i] - '0');
  }

 for(int i =0 ; i < sum.size(); i++)
 {
  cout<<sum[i];
 } 
}