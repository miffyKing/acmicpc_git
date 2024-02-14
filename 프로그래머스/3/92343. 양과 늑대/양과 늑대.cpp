#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include <unordered_map>

using namespace std;

// int maxSheep = 0;

// unordered_map<int, vector<int>> graphs(17);


// void dfs(int sheepCnt, int wolfCnt, int cur, vector<vector<int>> edges, vector<int> info)
// {
//     if (sheepCnt == wolfCnt && cur != 0)
//         return;
    
//     // if (info[cur] == 0) sheepCnt++;
//     // else wolfCnt++;
    
//     maxSheep = max(maxSheep, sheepCnt);
    
//     vector<int> tmp = graphs.count(cur) ? graphs[cur] : vector<int>();
//     tmp.insert(tmp.end(), )
    
//     for (int i = 0; i < graphs[cur].size(); i++)
//     {
//         // cout<<graphs[cur][i] << " "; 
//         int nextNode = graphs[cur][i];
        
//         if (info[nextNode] == 0)
//         {
//             dfs(sheepCnt+1, wolfCnt, nextNode,  edges, info);       
//         }
//         else 
//             dfs(sheepCnt, wolfCnt + 1, nextNode,  edges, info);   
        
//     }

// //    return;
// }


int maxScore = 1;

void DFS(int now, int sheep, int wolf, vector<int>& info, unordered_map<int, vector<int>>& graph, vector<int>& list) {
    maxScore = max(maxScore, sheep);
    if (sheep <= wolf) return;

    vector<int> temp = graph.count(now) ? graph[now] : vector<int>();
    temp.insert(temp.end(), list.begin(), list.end());
    temp.erase(remove(temp.begin(), temp.end(), now), temp.end());

    for (int x : temp) {
        if (info[x] == 0) {
            DFS(x, sheep + 1, wolf, info, graph, temp);
        } else {
            DFS(x, sheep, wolf + 1, info, graph, temp);
        }
    }
}


int solution(vector<int> info, vector<vector<int>> edges) {
unordered_map<int, vector<int>> graph;
    for (auto& edge : edges) {
        graph[edge[0]].push_back(edge[1]);
    }

    vector<int> initialList = {0};
    DFS(0, 1, 0, info, graph, initialList);
    return maxScore;

}