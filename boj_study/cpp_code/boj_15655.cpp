#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int isused[10002];
int buffer[10002];
int n,m;
vector<int> arr;

void func(int cur)
{
    if (cur == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout<<buffer[i] << ' ';
        }cout<<'\n';
        return ;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (cur != 0)
            {
                if(isused[i] != 1 && buffer[cur-1] < arr[i])
                {
                    isused[i]= 1;
                    buffer[cur] = arr[i];
                    func(cur+1);
                    isused[i] = 0;
                }
            }
            else 
            {
                if(isused[i] != 1)
                buffer[cur] = arr[i];
                isused[i] = 1;
                func(cur+1);
                isused[arr[i]]= 0;
            }        
        }
    }
}

int main()
{
    int tmp;
    cin>>n>>m;
    for (int i = 0; i < n; i++)
    {
        cin>>tmp;
        arr.push_back(tmp);
    }
    sort(arr.begin(), arr.end());
    
    func(0);

    return 0;
}