#include <iostream>
#include <vector>
#include <map>
#include <math.h>
using namespace std;

int main()
{

    int tc;
    cin>>tc;

    for (int idx = 0; idx < tc; idx++)
    {
        map <int,int> soinsoo_table;
        int n;
        cin>>n;

        for (int i = 2; i <= n; i++)
        {
            int cnt = 0;
            while (n % i == 0)
            {
                cnt++;
                n/=i;
            }
            soinsoo_table.insert({i, cnt});
        }
        for (auto iter : soinsoo_table)
        {
            if (iter.second != 0)
                cout<< iter.first << " " << iter.second << "\n";
        }
    }
    return 0;
}