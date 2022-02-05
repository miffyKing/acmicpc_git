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

int arr[32];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin>>n;
    
    if(n%2 == 1)
    {
        cout<<0;
        return 0;
    }
    arr[0] =1;
    arr[4] = 11;
    arr[2] = 3;
    
    for(int i = 6; i<= n; i++)
    {
        arr[i] = arr[i-2]*3;
        for(int j = 4; j<= i; j+=2)
        {
            arr[i] += arr[i-j]*2;
        }
        
    }
    cout<<arr[n];
}

