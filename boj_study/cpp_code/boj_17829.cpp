#include<iostream>
#include<string>
#include <map>
#include<set>
#include<stack>
#include<queue>
#include <vector>
#include <functional>
#include <algorithm>
#include<cmath>
#include <cstring>
#include <set>
#include <stdio.h>
//#include <string.h>

using namespace std;

int table[1026][1026];

int dnq( int startx, int starty)
{
    vector<int> x;
    x.push_back(table[startx][starty]);
    x.push_back(table[startx+1][starty]);
    x.push_back(table[startx][starty+1]);
    x.push_back(table[startx+1][starty+1]);
    
    sort(x.begin(), x.end(), greater<>());
    return x[1];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int n;
   
    
    cin>>n;
    for(int i =0; i< n; i++)
    {
        for(int j=0; j<n;j++)
        {
            cin>>table[i][j];
        }
    }
    
   // int arr[1025][1025];
   while(n >= 1)
   {
       for(int i =0; i<n ;i+=2)
       {
           for(int j =0; j<n; j+=2)
           {
               table[i/2][j/2] = dnq(i,j);
           }
       }
       n/=2;
   }
    
    cout<<table[0][0];
}
