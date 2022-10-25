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

int arr[1000002];
int checked[100002];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    for(int i = 1; i <= 10000; i++)
    {
        int selfnum = i;
        int tmp = i;
        while(tmp != 0)
        {
            int dividened = tmp%10;
            selfnum+=dividened;
            tmp/=10;
        }
        checked[selfnum] = 1;
    }
    
    for(int i =1; i<=10000; i++)
    {
        if(checked[i] != 1)
            cout<<i<<'\n';
    }
    
}
