#include <iostream>
#include <string>
#include <utility>
#include <algorithm>
#include <string.h>
#include <sstream>
#include <vector>
#include <set>

using namespace std;

int main()
{
  string n_str;
  getline(cin, n_str);
  int n = stoi(n_str);
  set<int> s;

  for (int i = 0; i < n; i++)
  {
    string word;
    vector<string> twoword;
    int input;
    getline(cin, word);

    stringstream ss(word);
    string tmp;
    while (getline(ss, tmp, ' '))
    {
      twoword.push_back(tmp);
    }

    cout << twoword[0] << "  :  " << twoword[1] << "\n";
    string order = twoword[0];
    int num = stoi(twoword[1]);
  }

  return 0;
}