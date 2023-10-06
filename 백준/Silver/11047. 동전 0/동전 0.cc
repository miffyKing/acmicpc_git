#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    
    long long n, k;
    long long arr[12];
    
    cin>>n>>k;
    for(int i = 0; i< n; i++)
        cin>>arr[n - i -1];

    int idx = 0;
    while(arr[idx] > k)
        idx++;
    int cnt = 0;
    while(k > 0)
    {
        k -= arr[idx];
        cnt++;
        if(k < 0)
        {
            k += arr[idx++];
            cnt--;
        }
        if(arr[idx] > k)
        {
            idx++;
        }
      //  cout<< "cyrrent arr[idx] is " << arr[idx] << " and k is " << k << '\n';
       // cnt++;
    }
    cout<< cnt<<'\n';
    //k보다 작은 금액중에 가장 큰 값을 골라서 계속 뺌
    //음수가 되면 그거보다 작은 금액으로 또 계속
    //가자!
    
    
    
    return 0;
}

