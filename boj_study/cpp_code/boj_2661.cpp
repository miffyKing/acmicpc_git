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

int arr[82];
int isused[82];
int n;
int flag = false;
int check(int cur)
{
    for(int len =1; len <= cur; len++)
    {
        int same =1;
        for(int idx =1; idx <= len; idx++)
        {
            if(arr[cur-len+idx] != arr[cur-2*len +idx]) { same =0;}
        }
        if(same == 1)
        {
            return 0;
        }
    }
    return 1;
    
}

int dp_func(int k )
{
  //  cout<< "k is " <<k <<'\n';
    if(flag == true)
        return 0;
    
    if(k==n+1)
    {
        
        for(int i=1; i<= n; i++)
        {
            cout<<arr[i];
        }
        cout<<'\n';
        flag = true;
        return 0;
    }
    else
    {
        for(int i =1; i<=3; i++)
        {
            arr[k] = i;
            if(check(k))
            {
                dp_func(k+1);
            }
            else
            {
                arr[k] = 0;
            }
        }
    }
    return 0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n;
   // arr[1] = 1;
    
    dp_func(1);
    /*for(int i =1; i<=n; i++)
    {
        cout<<arr[i];
    }
    cout<<'\n';*/
    return 0;
}
