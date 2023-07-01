#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>

using namespace std;

int main()
{
  int n;
  string s;
  set<string> maps;
  vector<pair<int, string> > array;
  getline(cin, s);
  n = stoi(s);
  for(int i = 0; i < n; i++)
  {
    getline(cin, s);
    if (i == 0)
    {
      maps.insert(s);
      array.push_back(make_pair( s.length(),s));
    }        
    if (maps.find(s) == maps.end())
    {
      maps.insert(s);
      array.push_back(make_pair( s.length(),s));
    }
    // else{
    //   cout<<"s is " << s << "\n";
    // }
  }

    sort(array.begin(), array.end());

   // cout<< " ===============================\n";
    for (int i= 0; i <array.size(); i++)
    {
      cout<<array[i].second<<"\n";
    }

  return 0;
}