#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int main()
{
    
    int tc;
    int l;
    int knight_pos[2];
    int go_to[2];
    
    cin >>tc;
    for (int i = 0; i < tc; i++)
    {
        int visited[302][302];
        
        int dir_x[8] = {1,1, 2,2, -1,-1, -2,-2};
        int dir_y[8] = {2,-2,1,-1,2,-2, 1, -1 };
        queue<pair<int,int>> q;

        cin >> l;

        for(int j = 0; j < l; j++)
        {
            for(int k = 0 ;k < l; k++)
            {
                visited[j][k] = 0;
            }
        }
        cin>>knight_pos[0]>>knight_pos[1];
        q.push({knight_pos[0],knight_pos[1]});
        visited[knight_pos[0]][knight_pos[1]] = 1;
        cin>>go_to[0]>>go_to[1];
        
        while(!q.empty())
        {
            pair<int,int> cur = q.front();
            q.pop();
            for(int j = 0; j < 8 ;j++)
            {
                int cx = cur.first + dir_x[j];
                int cy = cur.second + dir_y[j];
                if (cx < 0 || cx > l || cy < 0 || cy >l) continue;
                if (visited[cx][cy] != 0) continue;
            
                visited[cx][cy] = visited[cur.first][cur.second]+1;
                q.push({cx,cy});
            }
        }
    
        cout<<visited[go_to[0]][go_to[1]] -1<<'\n';
    }
}
