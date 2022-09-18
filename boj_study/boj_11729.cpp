
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long cnt = 0;


void func2(int a, int b, int n)
{
    cnt++;
    if(n==1)
        return ;
    func2(a, 6-a-b, n-1);
    func2(6-a-b, b, n-1);
}

void func(int a, int b, int n)
{
    cnt++;
    if(n==1)
    {
        cout<<a<< ' '<< b<<'\n';
        return ;
    }
        
    func(a, 6-a-b, n-1);
    cout<<a<< ' ' << b << '\n';
    func(6-a-b, b, n-1);
}
int main()
{
    int n;
    cin>>n;
    //func2(1,3,n);
    
    cout<< (1<<n)-1<<'\n';
    cout<<cnt<<'\n';
    func(1,3,n);
}
