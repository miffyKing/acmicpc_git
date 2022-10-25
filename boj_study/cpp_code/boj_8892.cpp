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

using namespace std;

int is_pelindrom(string x)
{
    int leng = (int)x.size();
    
    for(int i =0; 2*i < leng; i++)
    {
        if(x[i] != x[leng-i-1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string word[102];
    int T;
    cin>>T;
    
    for(int x =0; x< T; x++)
    {
        int k;
        cin>> k;
        for(int i =0; i< k; i++)
        {
            cin>>word[i];
        }
        string sum_str;
        int end_flag =0;
        for(int i =0; i< k; i++)
        {
            if(end_flag == 1)
                break;
            for(int j =0; j <k; j++)
            {
                if(end_flag ==1)
                    break;
                if(i ==j) continue;
                sum_str = word[i] + word[j];
                if(is_pelindrom(sum_str) == true)
                {
                    cout<<sum_str<<'\n';
                    end_flag =1;
                }
            }
        }
        if(end_flag == 0)
        {
            cout<<0<<'\n';
        }
    
        
    }
}
