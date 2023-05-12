#include <iostream>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

vector<string> split(string input, char delimiter)
{
  vector<string> result;
  stringstream ss(input);
  string tmp;

  while (getline(ss, tmp, delimiter))
    result.push_back(tmp);

  return result;
}

int main()
{
  int tc;
  cin >> tc;

  for (int idx = 0; idx < tc; idx++)
  {
    int flag = 0;
    string p;
    cin >> p;
    int n;
    cin >> n;
    string input;
    vector<int> x;
    cin >> input;
    string input2 = input.substr(1, input.length() - 2);
    vector<string> result = split(input2, ',');
    deque<string> q;

    for (int i = 0; i < result.size(); i++)
    {
      q.push_back(result[i]);
    }

    int rev = -1;
    for (int i = 0; i < p.length(); i++)
    {
      if (p[i] == 'R')
      {
        rev *= -1;
      }
      else if (p[i] == 'D')
      {
        if (q.empty() != 1)
        {
          if (rev == 1)
            q.pop_back();
          else
            q.pop_front();
        }
        else
        {
          cout << "error\n";
          flag = 1;
          break;
        }
      }
    }
    if (flag == 1)
      continue;
    if (rev == 1)
    {
      cout << "[";
      while (!q.empty())
      {
        string chunk = q.back();
        cout << chunk;
        q.pop_back();
        if (!q.empty())
        {
          cout<<",";
        }
      }
      cout<<"]\n";
    }
    else
    {
      cout << "[";
      while (!q.empty())
      {

        cout << q.front();
        q.pop_front();
        if(!q.empty())
        {
          cout<<",";
        }
      }
      cout<<"]\n";
    }
  }
  return 0;
}