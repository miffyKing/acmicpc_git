#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int n,m;
int isused[10];
int arr[10];
int cnt = 0;

void func(int cur)
{
    if(cur == m)
    {
        for(int i =0; i< m;i++)
        {
            cout<<arr[i] << ' ';
        }
        cout<<'\n';
        return ;
    }
    for(int i = 1; i<= n; i++)
    {
        //if(isused[i] != 1)
       //{
        //    isused[i] = 1;
            arr[cur] = i;
            func(cur+1);
          //  isused[i] = 0;
       // }
    }
}
int main()
{
    cin>>n>>m;
    func(0);
    return 0;
}
