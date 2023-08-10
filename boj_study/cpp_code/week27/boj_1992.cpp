#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string str;
char table[65][65];

void recur(int x, int y, int leng)
{

  if (leng == 0)
    return;
  
  str += "(";
 
  for (int idx = 0; idx < 4; idx++)
  {
    int flag = 0;
    int beginx, beginy;
    if (idx == 0) { beginx = x; beginy = y;}
    if (idx == 1) {beginx = x; beginy = y + leng/2;}
    if (idx == 2) {beginx = x + leng/2; beginy = y;}
    if (idx == 3) {beginx = x + leng/2; beginy = y + leng/2;}

    char comp = table[beginx][beginy];
    for (int i = beginx ; i < beginx + leng/2; i++)
    {
      for (int j = beginy; j < beginy + leng/2; j++)
      {
        if (table[i][j] != comp)
        {
          recur(beginx, beginy, leng/2);
          flag = 1;
          break;
        }
      }
      if (flag == 1)
        break;
    }
    if (flag == 0)
      str+=comp;
  }

  str += ")"; 
}

int main()
{
  int n;

  cin >> n;  
  for (int i = 0; i < n; i++)
  {
    string str2;
    cin >> str2;
    for (int j = 0; j < n; j++)
    {
      table[i][j] = str2[j];
    }
  }
  char comp = table[0][0];
  int flag = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (table[i][j] != comp)
      {
        flag = 1;
        break;
      }
    }
  }
  if (flag == 0)
  {
    cout<<table[0][0];
    return 0;
  }
  recur(0, 0, n);

  cout << str;
  return 0;
}