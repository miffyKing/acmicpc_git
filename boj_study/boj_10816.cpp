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

int n;
int m;
int card[500002];
vector<int> find_card;

int lowerbound(int target, int size )
{
    int left = 0; int right  = size-1;
    while(left< right)
    {
        int middle = (left+right)/2;
        if(card[middle] >= target)
        {
            right = middle;
        }
        else
        {
            left = middle +1;
        }
        
    }
    return right;
}
int upperbound(int target, int size)
{
    int left = 0;
    int right = size-1;
    while(left < right)
    {
        int middle = (left+right)/2;
        if (card[middle] > target) {
            right = middle;
        }
        else
        {
            left = middle+1;
        }
        
    }
    return left;
    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
 
    //long long int middle;
    
    cin>>n;
    for(int i =0; i <n;i++)
    {
        cin>>card[i];
    }
    
    cin>>m;
    int tmp;
    for(int i =0; i <m;i++)
    {
        cin>> tmp;
        find_card.push_back(tmp);
    }
    
    sort(card, card+n);
    //sort(find_card, find_card+m);
    
    for(int i =0; i< m ;i++)
    {
        int target = find_card[i];
        int lower_position;
        int upper_position;
        
        lower_position = lowerbound(target, n);
        upper_position = upperbound(target, n);
        if(upper_position == n-1 && card[n-1] == find_card[i])
            upper_position++;
        cout<<upper_position - lower_position << ' ';
    }
   


    return 0;
}
