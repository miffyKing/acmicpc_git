#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    int input;
    long long arr[1000002];
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;
    arr[4] = 7;
    arr[5] = 13;
    
    for(int i = 6; i<= 1000000; i++)
    {
        arr[i] = (arr[i-1]+arr[i-2]+arr[i-3])%1000000009;
    }
    cin>>n;
    for(int i = 0; i< n ; i++)
    {
        cin>>input;
        cout<<arr[input]<<'\n';
    
    }
    return 0;
}
