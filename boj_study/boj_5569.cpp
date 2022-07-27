#include <vector>
#include <iostream>
#include <string.h>

using namespace std;

int visited[102][102];
int width, height;
vector<pair<int,int>> node[102][102];
int answer = 0;
void dfs_func(int x_cor, int y_cor, int cur_changed , int up_or_right);

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    
    
    cin>>width>>height;
    
    for(int i =1; i<= width; i++)
    {
        for(int j =1; j<= height; j++)
        {
            node[i][j].push_back(make_pair(i, j+1));
            node[i][j].push_back(make_pair(i+1, j));
            //[i][j+1].push_back(make_pair(i, j));
            //node[i+1][j].push_back(make_pair(i,j));
        }
    }
    
    
    for(int i =1; i<= width; i++)
    {
        for(int j =1; j<= height; j++)
        {
            for(int k =0; k< node[i][j].size(); k++)
            {
                cout<<"i and j is " << i <<' ' << j << ' ' << node[i][j][k].first << ' ' << node[i][j][k].second << '\n';
            }
        }
    }
    
    dfs_func(1,1, 0, 0);
    memset(visited, 0 , sizeof(visited));
    cout<<"----------------\n";
    dfs_func(1, 1, 0, 1);
    //1,2번째 인자는 시작 좌표
    //3번째 인자 -> 직전 방향전환 했으면 1, 아님 0
    //4번째 인자 -> 직전 방향전환이 오른쪽이면 0, 위쪽이면 1
    cout<< answer ;
    
    return 0;
}

void dfs_func(int x_cor, int y_cor, int cur_changed , int up_or_right)
{
    
    if(x_cor == width && y_cor == height)
    {
        cout<<"!!!!!\n";
        answer++;
        //return ;
    }
    for(int i =0; i< node[x_cor][y_cor].size(); i++)
    {
        int new_X = node[x_cor][y_cor][i].first;
        int new_Y = node[x_cor][y_cor][i].second;       //새 xy 좌표
        if(new_X > width || new_Y > height) continue;
        if(up_or_right == 1 && cur_changed == 1) // 위로 이동중이고 직전에 방향전환을 함
        {//그럼 지금 새 x,y 좌표가 오른쪽으로 가는거면 안되지
            if(new_X > x_cor)
            {
                cout<<"CASE ERROR 1\n";
                continue;
            }
            else
            {
                cout<< "CASE 1 x y : " <<new_X<< ' '<< new_Y << '\n';
                dfs_func(new_X, new_Y, 0, 1);   //한칸 이동한거, 직전방향전환X, 위로
            }
        }
        else if(up_or_right == 1 && cur_changed == 0) // 위로 이동중, 직전방향전환 X일 때
        {// 위,오른쪽 어디든 갈 수 있으니 그냥 dfs
            if(new_X > x_cor)   //오른쪽으로
            {
                cout<< "CASE 2 x y : " <<new_X<< ' '<< new_Y << '\n';
                dfs_func(new_X, new_Y, 1, 0);
            }
            else
            {
                cout<< "CASE 3 x y : " <<new_X<<' '<<  new_Y << '\n';
                dfs_func(new_X, new_Y, 0, 1);
            }
        }
        if(up_or_right == 0 && cur_changed == 1) //오른쪽 이동중, 직전 방향전환 O
        {
            if(new_Y > y_cor)   //직전에 방향전환해서 오른쪽으로 가던걸 바로 위로?NO
            {
                cout<<"CASE ERROR 2\n";
                continue;
            }
            else
            {
                cout<< "CASE 4 x y : " <<new_X<<' '<<  new_Y << '\n';
                dfs_func(new_X, new_Y, 0,0);    //한칸 이동, 직.방.전 X, 오른쪽으로
            }
        }
        else if(up_or_right == 0 && cur_changed == 0)    //오른쪽이동, 직.방.전 X
        {// 위,오른쪽 어디든..
            if(new_Y > y_cor)   //오른쪽으로..
            {
                cout<< "CASE 5 x y : " <<new_X<<' '<<  new_Y << '\n';
                dfs_func(new_X, new_Y, 0, 0);       //직.방.전 X , 오른쪽
            }
            else
            {
                cout<< "CASE 6 x y : " <<new_X<<' '<<  new_Y << '\n';
                dfs_func(new_X, new_Y, 1, 1);
            }
        }
    }
   // return ret ;
}

