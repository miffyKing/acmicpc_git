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

int dp[202][202];
int leng_sum =0;
string s1,s2,s3;
int dp_func(int flag1, int flag2, int flag3)
{
    int &ret = dp[flag1][flag2];
    if(flag3 == leng_sum)  //   끝에 다다르면 종료
    {
        return 1;
    }
    //cout<<"RET IS " << ret <<'\n';
    
    //dp[flag1][flag2] = ret;
    if(ret != -1)
    {
        return ret;
    }
    ret =0;
    
    
    if(s1[flag1] == s3[flag3] && flag1 < (int)s1.length())
    {
        ret = dp_func(flag1+1, flag2, flag3+1);
    }
    if(s2[flag2] == s3[flag3] && flag2 < (int)s2.length())
    {
        ret = max(ret, dp_func(flag1, flag2+1, flag3+1));           //위에서 첫번째 같았던거랑 더 큰값 비교..
    }
   
    return ret;
    
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    
    //int flag =0;
    cin>> n;
    
    for(int x=0; x<n; x++)
    {
        //string s1,s2,s3;
        memset(dp, -1, sizeof(dp));
        cin>>s1; cin>>s2; cin>>s3;
        leng_sum = (int)s1.length() + (int)s2.length();
        
        if(dp_func(0,0,0))
            cout<<"Data set "<< x+1<<": yes\n";
        else
            cout<<"Data set "<< x+1<<": no\n";
    }
    
}
