#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cnt = 0;
int n,m;
int arr[10];
int isused[10];
int isused_num[10];
int buffer[10];

void func(int cur)
{
    if (cur == m)
    {
        for(int i =0; i< m; i++)
        {
            cout<<buffer[i]<< ' ';
        }
        cout<<'\n';
        return;
    }
  int before = 0;
    for(int i = 0; i< n; i++)
    {
        if(isused[i] != 1 && before != arr[i])
        {
            buffer[cur] = arr[i];
            before = buffer[cur];
            
            if (cur != 0 && buffer[cur-1] <= buffer[cur])
            {
                isused[i] = 1;
                func(cur+1);
                isused[i] = 0;
            }
            else if (cur == 0)
            {
                isused[i] = 1;
                func(cur+1);
                isused[i] = 0;
            }
        }
    }
}

int main()
{
    cin>>n>>m;
    for(int i =0; i< n; i++)
        cin>>arr[i];
    sort(arr, arr+n);
    func(0);
    return 0;
}
