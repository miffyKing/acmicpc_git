#include <iostream>
#include <vector>
#include <math.h>
#include <set>

using namespace std;

int euclidean(int a, int b)
{
    int r = a % b;
    if(r== 0)
        return b;
    return euclidean(b,r);
}


int get_lines(int n)
{
    set<pair<int,int>> lines;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (euclidean(i,n) == 1)
        {
                cnt++;
        }
        if (euclidean(n,i) == 1)
        {
            cnt++;
        }
        
    }
    return cnt;
}

int table[1002];

int main()
{
    int tc;
    
    cin>>tc;
    
    for (int i = 1; i <= 1000; i++)
    {
        table[i] = table[i-1] + get_lines(i);
    }
    //cout<<"!!!\n";
    
    for (int idx =0; idx < tc; idx++)
    {
        int n;
        cin>>n;
        cout<< table[n]+1<<"\n";
    }
    return 0;
}
