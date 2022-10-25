#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int visited[22];
int arr[22];
int n,s;
int cnt =0;
void func(int cur, long long sum)
{
    if(cur ==n)
    {
        if(sum == s)
            cnt++;
        return;
    }
    func(cur+1, sum);
    func(cur+1, sum+arr[cur]);
}
int main() 
{
    cin>>n>>s;
    for(int i =0; i< n; i++)
    {
        cin>>arr[i];
    }
    func(0,0);
    if (s==0) cnt--;
    cout<<cnt<<'\n';
}
