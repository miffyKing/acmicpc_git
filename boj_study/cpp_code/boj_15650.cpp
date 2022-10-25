
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
int cnt = 0;
int isused[9];
int arr[9];

void func(int cur)
{
    if(cur == m)
    {
        for(int i = 0; i < m; i++)
        {
            cout<<arr[i] << ' ';
        }
        cout<<'\n';
        return;
    }
    for(int i = 1; i<= n; i++)
    {
        if(isused[i] != 1)
        {
            isused[i] = 1;
            arr[cur] = i;
            if (arr[cur-1] < arr[cur])
                func(cur+1);
            isused[i] = 0;
        }
    }
}

int main()
{
    cin>>n>>m;
    
    func(0);
    return 0;
}
