#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,m;
int isused[10002];
int buffer[10002];
vector<int> arr;

void func(int cur)
{
    if(cur == m)
    {
        for (int i =0; i < m ; i++)
        {
            cout<<buffer[i] << " ";
        }cout<<"\n";
        return ;
    }   
    int before = 0;
    for (int i = 0; i < n; i++)
    {
       if (cur != 0)
       {
        if (buffer[cur -1] <= arr[i] && before != arr[i])
        {
            buffer[cur] = arr[i];
            before = arr[i];
            func(cur + 1);
        }
       
       }
       else
       {
            if (before != arr[i])
            {

                buffer[cur] = arr[i];
                before = arr[i];
                func(cur + 1);
            }
            
       }
    }
}

int main()
{
    cin>>n>>m;
    int tmp;
    for(int i = 0; i < n; i++)
    {  
        cin>>tmp;
        arr.push_back(tmp);
    }
    sort(arr.begin(), arr.end());
    func(0);

    return 0;
}