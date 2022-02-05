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

vector <int> arr;
vector <int> arr2;
deque<int> card;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin>>n;
    int tmp;
    for(int i=0; i<n;i++)
    {
        cin>>tmp;
        arr.push_back(tmp);
    }
    for(int i =0; i< n;i++)
    {
        arr2.push_back(arr[n-i-1]);
    }
    
    for(int i = 1; i<=n; i++)
    {
        if(arr2[i-1] == 3)
        {
            //cout<<"3\n";
            card.push_back(i);
        }
        else if(arr2[i-1] ==2)
        {
            //cout<<"2\n";
            int tmp;
            
            tmp = card.front();
            card.pop_front();
            card.push_front(i);
            card.push_front(tmp);
        }
        else if(arr2[i-1] == 1)
        {
            //cout<<"1\n";
            card.push_front(i);
        }
    }
    for(int i =0; i< n ; i++)
    {
        cout<<card.front()<< ' ';
        card.pop_front();
    }
}
