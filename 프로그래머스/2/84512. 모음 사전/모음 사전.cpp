#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int cnt = 0;
int ans = 0;
char arr[5] = {'A', 'E', 'I', 'O', 'U'};
bool endflag = false;
void dfs(string cur, string word)
{
    
    //cout<< "cur is  " << cur << "\n";
    if (cur.size() > 5)
    {
        return;
    }
    if (cur == word)
    {
        ans = cnt;
        endflag = true;
        return;
    }
    cnt++;
    
    for (int i = 0; i < 5; i++)
    {
        dfs(cur + arr[i], word);
        if (endflag == true)
            return;
    }
    return;
}

int solution(string word) {
    int answer = 0;
    vector<string> arr;
    
    dfs("", word);
    
    return cnt;
}