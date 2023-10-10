#include <string>
#include <vector>
#include <utility>
#include <iostream>
#include <math.h>

using namespace std;

pair<string,int> wordId[50];
//dfs 를 위해, 자기랑 한글자만 차이나는 단어들을 배열로 만들어 놓자.
vector<int> tables[52];
int isvisited[52];
int min_route = 100;
int targetIdx = 10000;

void dfs(int cur, int cnt)
{
    if (cur == targetIdx)
    {
        min_route = min(min_route, cnt);
        return;
    }
    isvisited[cur] = 1;
    for (int i = 0; i < tables[cur].size(); i++)
    {
        int nextcur = tables[cur][i];
        if (isvisited[nextcur] == 1) continue;
        dfs(nextcur, cnt+1);
    }
    return ;
}


bool check_onediff(string a, string b)
{
    int cnt = 0;
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] != b[i])
            cnt++;
    }
    if (cnt == 1) return true;
    return false;
}

int solution(string begin, string target, vector<string> words) {
    
    //cout<<"!!!!\n";
    int answer = 0;

    for (int i = 0; i < words.size(); i++)
    {
        if (words[i] == target)
            targetIdx = i;
        wordId[i] = make_pair(words[i], i);
    }
        
        
    for (int i = 0; i < words.size(); i++)
    {
        for (int j = i+1; j < words.size(); j++)
        {
            //j 번째 단어와 i 단어를 비교해 차이가 1 뿐이면 i vector 뒤에 추가한다.
            if (check_onediff(words[i], words[j]) == true)
            {
                tables[i].push_back(j);
                tables[j].push_back(i);
            }
        }
    }
//     for (int i = 0; i < words.size(); i++)
//     {
//         for (int j = 0; j < tables[i].size(); j++)
//         {
//             cout<< tables[i][j] << " ";
//         } cout<<"\n";
//     }
    
    if (targetIdx == 10000)
        return 0;
    
    for (int i = 0; i < words.size(); i++)
    {
        if (check_onediff(begin, words[i]) == true)
        {
            //cout<<"dfs starts from" << words[i] << "\n";
            dfs(i, 1);
            //탐색 시작의 후보가 되는 녀석들
        }
    }
    //cout<< "min route " << min_route<<"\n";
    if (min_route == 100)
        return 0;
    return min_route;

}