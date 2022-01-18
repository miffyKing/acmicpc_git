#include<iostream>
#include<string>
#include <map>
#include<set>
#include<stack>
#include <vector>
#include <functional>
#include <algorithm>
#include<cmath>

#include <set>
using namespace std;


string arr[1004];
long long hash_val[1004][1004];
long long p = 27;

int main()
{
    
    set<int> num_set[1003];
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int r,c;
     cin>> r >>c;
    for(int i =0; i< r; i++)
    {
            cin>> arr[i];
    }
    
    //int count = 0;
    long long pp =1;
    for (int i = r - 1; i >= 0; i--, pp = pp * p)
    {
        for (int j = 0; j < c; j++)
        {
            hash_val[i][j] = hash_val[i + 1][j] + (arr[i][j]-'a' + 1) * pp;
        }
    }
    
    int count = 0;
    int flag =0;
    for(int i =0; i<r; i++)
    {
        sort(hash_val[i], hash_val[i]+c);
        for(int j =0; j < c-1; j++)
        {
            if(hash_val[i][j] == hash_val[i][j+1])
            {
                cout<< count-1;
                return 0;
            }
        }
        count++;
    }
  
   
    cout<<count-1;
    
    /*
    for(int i = r; i> 0; i--)
    {
        for(int j =c; j > 0; j--)
        {
            for(int k = i; k <= r; k++ )
            {
                hash_val[i][j] += ((int)arr[k][j] - 'a' +1)* pow(27,k-i);
            }
            num_set[i].insert(hash_val[i][j]);
        }
    }*/
    /*
    for(int i=1; i<=r; i++)
    {
        if(num_set[i].size() < c)
        {
            break;
        }
        else
        {
            count++;
        }
    }
    if(count == 0)
    {
        cout<<0<<'\n';
    }
    else
    {
        cout<<count-1<<'\n';
    }*/
    
}

