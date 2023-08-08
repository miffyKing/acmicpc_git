#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    int array[32];
    
    cin>>n;
    array[1] = 0;
    array[2] = 3;
    array[3] = 0;
    array[4] = 11;
    
    if(n%2 == 1)
    {
        cout<<0<<'\n';
        return 0;
    }
    for(int i = 6; i <= n; i+=2)
    {
        array[i] = array[i-2] * 3;
        for(int j= 2; j< i-2; j+=2)
        {
           // cout<<"!!!\n";
            array[i] += (array[j]*2);
        }
        array[i]+=2;
    }
    cout<<array[n]<<'\n';
    return 0;
}
