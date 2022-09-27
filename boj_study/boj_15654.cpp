
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int cnt  = 0;
int arr[10];
int buffer[10];
int isused[10];

void func(int cur)
{
    if (cur == m)
    {
        for(int i = 0; i< m; i++)
        {
            cout<<buffer[i] << ' ';
        }
        cout<<'\n';
        return ;
    }
    
    for(int i = 0; i < n; i++)
    {
        if (isused[i] != 1)
        {
            isused[i] = 1;
            buffer[cur] = arr[i];
            func(cur+1);
            isused[i] = 0;
        }
    }
}
int main()
{
    cin>>n>>m;
    for(int i = 0;i < n; i++)
        cin>>arr[i];
    sort(arr+0, arr+n);
    func(0);
    return 0;
}
