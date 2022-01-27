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

bool compare( tuple<double, int, int> a, tuple<double , int, int> b)
{
    if( get<0>(a) == get<0>(b))
        return get<1>(a) > get<1>(b);
    else
        return get<0>(a) < get<0>(b);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    int arr[1002];
    int arr2[1002];
    vector <tuple<double, int, int>> arr3;
    cin>>n;
    for(int i =0; i< n; i++)
    {
        cin>>arr[i] >> arr2[i];
        arr3.push_back(make_tuple((double)arr2[i]/arr[i], i, arr[i]));
    }
    sort(arr3.begin(), arr3.end(), compare);
    
    for(int i =n-1; i>=0;i--)
    {
        cout<< get<1>(arr3[i]) +1<<' ';
    }
    cout<<'\n';
}
