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
char s[1000005];
char p[1000005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    int m;
   
    cin >>n;
    cin>>m;
    cin>>s;
    
    for(int i =0; i< n*2+1; i++)
    {
        if(i%2 == 0)
            p[i] = 'I';
        else
            p[i] = 'O';
    }
   // cout<<"P is" << p<<'\n';
    int count =0;
    for(int i =0; i< sizeof(s); i++)
    {
        if(!strncmp(s+i, p, 2*n+1))
        {
            count++;
        }
    }
    cout<<count<<'\n';
}
