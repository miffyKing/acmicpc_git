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
long long int bob[1002];
long long int alice[1002];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n;
    for(int i =0; i< n; i++)
    {
        cin>>alice[i];
    }
    for(int i=0; i<n; i++)
    {
        cin>>bob[i];
    }
    sort(alice, alice+n);
    sort(bob, bob+n);
   
    long long int max_val =0;
    
    for(int i =0; i<n; i++)
    {
        long long int tmp = 1e12;;
        
        for(int j =0; j < n; j++)
        {
            tmp = min(tmp, abs(alice[i]-bob[j]));
        }
        max_val = max(tmp, max_val);
    }
    
    cout<<max_val;
}

