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

long long int x;

bool compare( const tuple<int, int, int> & a, const tuple <int,int, int> &b)
{
    return get<2>(a) > get<2>(b);
}
vector <tuple<int, int, int>> arr;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    int tmp1, tmp2;
    cin>> n >>x;
    long long int sum = 0;
    long long int rate =0;
    
    for(int i =0; i< n; i++)
    {
        cin>> tmp1 >>tmp2;
        rate += max(tmp1, tmp2);                   //일단 만족도 합
        int larger, smaller;
        if(tmp1 > tmp2)
        {
            larger  =tmp1; smaller = tmp2;
        }
        else{
            larger = tmp2; smaller =tmp2;
        }
        
        arr.push_back(make_tuple(larger, smaller,  tmp2-tmp1));
    }
    
    sort(arr.begin(), arr.end(), compare);
    
    for(int i =0; i< n; i++)
    {
        if( get<2>(arr[i]) > 0)
        {
            sum += 1000;
        }
        else
            sum += 5000;
    }
    //일단 무조건 5000원으로 전부 먹는 경우로 시작해서, 금액에 맞게 조절하고, 1000원이 더 만족도가 클때를 본다
  // cout<< "first rate : " << rate << "sum :  " << sum << '\n';
    
    int i = 0;
    
    while(sum > x)
    {
        if(get<2>(arr[i]) <= 0)
        {
            sum -= 4000;
            rate += get<2>(arr[i]);
        }
       // cout<< "current sum is " << sum << "current rate  :  " << rate << "     " << i <<'\n';
        i++;
    }
    cout<< rate<<'\n';

    
    
}

