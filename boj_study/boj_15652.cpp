
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int n,m;
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
    for(int  i = 1; i<= n; i++)
    {
        if (cur == 0)
        {
            arr[cur] = i;
            func(cur +1);
        }
        else
        {
            if (arr[cur-1] <= i)
            {
                arr[cur] = i;
                func(cur+1);
            }
        }
        
    }
}

int main()
{
    cin>>n>>m;
 
    func(0);
    return 0;
}
