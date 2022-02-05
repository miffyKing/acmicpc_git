#include<iostream>
#include<string>
#include <map>
#include<set>
#include<stack>
#include <vector>
#include <functional>
#include <algorithm>
#include<cmath>
#include <cstring>
#include <set>
#include <stdio.h>
//#include <string.h>

using namespace std;

int n;
int m;
int arr[10];
int isused[10];

void dp_func(int k)
{
    if(k == m)
    {
        for(int i =0; i<m;i++)
        {
            cout<<arr[i]<<' ';
        }
        cout<<'\n';
        return;
    }
    for(int i =1; i<=n; i++)
    {
        if(k==0)
        {
            arr[k] = i;
            isused[i] =1;
            dp_func(k+1);
            isused[i] =0;
        }
        else if(isused[i] != 1 && arr[k-1] < i)
        {
            arr[k] =i;
            isused[i] = 1;
            dp_func(k+1);
            isused[i] =0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n>>m;
    
    dp_func(0);
    
}

