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

int dp_arr[1003];
int a[1003];
int k;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //memset(dp_arr, -1, sizeof(dp_arr));
    int n;
    
    cin>>n;
    cin>>k;
    double pr = n;
    for(int i=0; i < k; i++)
    {
        cin>> a[i];
        double tmp = 0.0;
        tmp += pr*(1.0 -(double)a[i]/n);
        tmp += (n - pr)*((double)a[i] /n);
        pr = tmp;
    }
    cout<<fixed;
    cout.precision(13);
    cout<<pr;
    
}
