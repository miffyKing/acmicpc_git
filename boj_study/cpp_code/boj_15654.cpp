#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr;
int isused[10002];
int buffer[10002];

int n, m;
void func(int cur)
{
    if(cur == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout<<buffer[i] << ' ';
        }       
        cout<<"\n";
        return ;
    }
    for (int i = 0; i < n; i++)
    {
        if (isused[i] != 1)
        {
            isused[i] = 1;
            buffer[cur] = arr[i];
            func(cur+1);
            isused[i] = 0;
        }
    }
}

int main()
{    
    int tmp;

    cin>>n>>m;

    for(int i = 0; i < n; i++)
    {
        cin>>tmp;
        arr.push_back(tmp);
    }
    sort(arr.begin(), arr.end());

    func(0);
    return 0;
}