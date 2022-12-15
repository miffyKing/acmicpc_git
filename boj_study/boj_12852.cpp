#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
    int n;
    int table[1000002];
    
    cin>>n;
    
    for(int i = 0; i < n; i++)
        table[i+1] = i+1;
    
    
    for (int i = 2; i <= n; i++)
    {
        if (i%2 == 0)
            table[i] = min(table[i/2], table[i]);
        if (i % 3 == 0)
            table[i] = min(table[i/3], table[i]);
        table[i] = min(table[i], table[i-1])+1;
    }
    cout<< table[n] - 1<<'\n';
    
    while (n != 0)
    {
        cout<<n<< " ";
        if (table[n] == table[n-1]+ 1)
            n = n-1;
        else if (n % 2 == 0 && table[n] == table[n/2] + 1)
            n = n/2;
        else if (n % 3 == 0 && table[n] == table[n/3] + 1)
            n = n/3;
    }
    
    return 0;
    
}
