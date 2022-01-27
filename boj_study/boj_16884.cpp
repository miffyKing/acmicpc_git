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


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    for(int i=0; i< t; i++)
    {
        int n;
        cin>>n;
        if(n%2 ==1)
            cout<<"koosaga\n";
        else
            cout<<"cubelover\n";
        
    }
}
