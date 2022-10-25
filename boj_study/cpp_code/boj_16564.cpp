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

long long int n,k;
//vector<long long int> level;
vector<long long int> original_level;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    long long int left;
    long long int right;
    
    cin>>n>>k;
    long long int tmp;
    for(int i =0; i<n;i++)
    {
        cin>>tmp;
        original_level.push_back(tmp);
    }
    
    sort(original_level.begin(), original_level.end());
  
    left =0; right = 2000000001;
    long long int ans;

    while(left <=right)
    {
        long long int middle = (left+right)/2;
        long long int sum =0;
        for(int i=0; i<n;i++)
        {
            sum= sum+ max(middle - original_level[i], (long long int)0);
        }
        
        if(sum > k)
        {
            right = middle-1;;
        }
        else
        {
            ans = middle;
            left = middle+1;
        }
    }
    cout<<ans;
    
    
}
