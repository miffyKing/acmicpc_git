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

double dp_arr[1000004];


double dp_func(int n)
{
    double ret = 0.0;
    if(n <= 0)                          //남은 뽑아야할 사탕개수가 0이 되면 0 리턴해야지
    {
     //   cout<<"1\n";
        return 0.0;
    }
    if(dp_arr[n] >= 0.0)
    {
       // cout<<"2\n";
        
        return dp_arr[n];
    }
    
    for(int i = 1; i <= 6; i++)
    {
        ret += (1+ dp_func(n-i))/6.0;     // 주사위에서 1,2,3,4,5,6 뽑으면 남는 뽑아야할 사탕수는 n - i개. 1번 던졌으니 1더해주기
    }
    
    return  dp_arr[n] = ret;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    memset(dp_arr, -1, sizeof(dp_arr));
    
    cin>> n;
    
    cout<<fixed;                        //이거 해야 소수점이 찍힌다고 함
    cout.precision(13);
    cout<<dp_func(n);                   //처음인자 n 부터 시작해서 dp
    
    return 0;
}
