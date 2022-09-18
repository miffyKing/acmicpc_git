#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int visited[8];
int arr[8];
int cnt = 0;
int n, m;
void func(int cur)
{
    if (cur == m)
    {
        for(int i =0; i< m; i++)
            cout<< arr[i] << ' ';
        cout<<'\n';
        return;
    }
    for(int i  = 1; i<= n; i++)
    {
        if(visited[i]!= 1)
        {
            visited[i] = 1;
            arr[cur] = i;
            func(cur+1);
            visited[i] = 0;
        }
    }
    
}
int main()
{
    cin>>n>>m;
    func(0);
    
}
