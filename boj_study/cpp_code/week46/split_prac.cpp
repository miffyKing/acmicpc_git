#include <string.h>
#include <sstream>
#include <iostream>

using namespace std;

vector<string> split(string str, char delim )
{
  vector<string> ret;
  stringstream ss(str);
  string tmp;
  
  while(getline(ss, tmp, delim)) 
  {
    ret.push_back(tmp);
  }
  return ret;
}
int main()
{
  string str = "aaaa | bbb| ccc|| dddd";
  vector<string> result = split(str, '|');
  for (int i = 0; i < result.size(); i++)
  {
    cout<<result[i] << "\n";
  }

  return 0;
}