#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    
    for(int i = 0; i < n; i++)
    {
        for(int j = n-1; j>i; j--)
        {
            cout<<' ';
        }
        int stars = (i+1)*2-1;
        for(int i = 0; i< stars; i++)
        {
            cout<<'*'; 
        }
        cout<<'\n';
    }
    return 0;
}


