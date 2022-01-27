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

bool arr[1002];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    
    cin>>n;
    //상근이가 이기는게 true, 반대가 false
    
    arr[1] = true;
    arr[2] = false;
    arr[3] = true;
    for(int i =4; i <= n; i++)
    {
        if(arr[i -1] == false || arr[i-3] == false)
        {
            arr[i] = true;
        }
        else
            arr[i] = false;
    }
    if(arr[n] == true)
    {
        cout<<"SK\n";
    }
    else
        cout<<"CY\n";
}
