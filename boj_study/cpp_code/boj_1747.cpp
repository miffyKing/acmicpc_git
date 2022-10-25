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

int is_prime(int n)
{
    double n_tmp = sqrt(n);
    //n = (int)n_tmp;
    //out<<"n &  ntmp && abs(n_tmp) is " << n << ' '<< n_tmp<<' ' <<abs(n_tmp)<<'\n';
    int divisor = 2;
    while(divisor <= abs(n_tmp))
    {
        if(n%divisor == 0)
            return 1;
        divisor++;
    }
    return 0;
}
int is_pelin(int n)
{
    int i =1;
    int cnt = 0;
    for(int j = 0; j< 7; j++)
    {
        if(n/10 == 0)
            break;
       arr[i] = n%10;
       n/=10;
       i++;
    //   cout<<"i is " <<i<<'\n';
    }
    arr[i] = n%10;
   // cout<<"i is " << i <<'\n';
    for(int j =1; j <= i/2; j++)
    {
        if(arr[j] != arr[i-j+1])
            return 0;
        else
            cnt++;
    }
    if(cnt == i/2)
        return 2;
    else
        return 1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin>>n;
    if(n ==1)
    {
        cout<<2;
        return 0;
    }
    while(1)
    {
        
        if(is_prime(n) == 0)
        {
           // cout<<n << " is prime num\n";
            if(is_pelin(n) == 2)
            {
                cout<< n<<'\n';
                break;
            }
            //break;
        }
        n++;
        
    }
}
