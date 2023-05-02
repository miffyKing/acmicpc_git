#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;
 
    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }
    return answer;
}

int main()
{

  string input;
  cin>>input;
  vector<string> result = split(input, '/');
  int k = stoi(result[0]);
  int d = stoi(result[1]);
  int a = stoi(result[2]);

  if (k + a < d || d == 0)
  {
    cout<<"hasu\n";
    return 0;
  }
  cout<<"gosu\n";
  return 0;
}