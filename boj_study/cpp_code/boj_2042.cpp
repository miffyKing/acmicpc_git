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


long long int n,m,k,a,b,c;
long long int arr[100002];
//long long int arr2[10000002];
long long int tree[2000002];
long long int tree2[2000002];

long long int init(long long int N, long long int s, long long int e)
{
    if(s==e) return tree[N] = arr[s];
    long long int mid = (s+e)/2;
    return tree[N] = min(init(N*2, s, mid) , init(N*2 +1, mid+1, e));

}
long long int init2(long long int N, long long int s, long long int e)
{
    if(s==e) return tree2[N] = arr[s];
    long long int mid = (s+e)/2;
    return tree2[N] = max(init2(N*2, s, mid) , init2(N*2 +1, mid+1, e));

}
/*
void update(long long int N, long long int s, long long int e, long long int idx, long long int val)
{
    if(idx >e || idx <s) return;
    if(s ==e) {
        if(idx == s) tree[N] = val;
        return;
    }
    long long int mid = (s+e)/2;
    update(N*2, s, mid, idx, val);
    update(N*2+1, mid+1, e, idx, val);
    tree[N] = tree[N*2] + tree[N*2 +1];
}
*/
long long int query(long long int N, long long int s, long long int e, long long int l , long long int r )
{
    if(l>e || r <s) return 1000000001;
    if(l <= s && e <=r ) return tree[N];
    long long int mid = (s+e)/2;
    return min(query(N*2, s, mid, l, r) , query(N*2+1, mid+1, e, l, r));
}

long long int query2 (long long int N, long long int s, long long int e, long long int l , long long int r )
{
    if(l>e || r <s) return 0;
    if(l <= s && e <=r ) return tree2[N];
    long long int mid = (s+e)/2;
    return max(query2(N*2, s, mid, l, r) , query2(N*2+1, mid+1, e, l, r));
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n>>k;
    for(int i=0; i< n; i++)
    {
        cin>>arr[i];
        //arr2[i] =arr[i];
    }
    init(1, 0, n-1);
    init2(1,0, n-1);
    /*
    cout<<'\n';
    
    for(int i =0 ; i< 20; i++)
    {
        cout<<tree[i]<<' ';
    }
    cout<<'\n';
    
    for(int i =0 ; i< 20; i++)
    {
        cout<<tree2[i]<<' ';
    }
    cout<<'\n';
    */
    while(k--)
    {
        cin>>b>>c;
        
       // update(1,0,n-1, b-1, c);
         cout<<query(1,0,n-1, b-1, c-1) << ' ' << query2(1, 0 , n-1, b-1, c-1)<<'\n';
    }

}
