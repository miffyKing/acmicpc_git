#include <iostream>
#include <vector>
 
using namespace std;
 
int main()
{
    int n, m;
    
    cin>>n>>m;
    for (int i = 0; i < n-1; i++)
    {
        if (i < n - m)
        {
            cout<< i << " " << i+1 <<"\n";
        }
        
        else
        {
            cout<< n-m << " " << i+1 << "\n";
        }
    }
    return 0;
}
 
