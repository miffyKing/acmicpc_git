#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int get_gcd(int a, int b)
{
    int idx = 2;
    int value = 1;
    while(idx <= a && idx <= b)
    {
        if (a%idx != 0 || b%idx != 0)
        {
            idx++;
        }
        else {
            value*= idx;
            a /= idx;
            b /= idx;
        }
    }
    return value;
    
}

long long int get_total(vector<int> lsts)
{
    long long int sum = 0;
    for (int i = 0; i < lsts.size(); i++)
    {
        for (int j = 0; j < lsts.size(); j++)
        {
            if(i == j) continue;
//            cout << "i and j are [" << lsts[i] << " " << lsts[j] << "] and gcd is " <<get_gcd(lsts[i], lsts[j])<<"\n";
            sum += get_gcd(lsts[i], lsts[j]);
        }
    }
    return sum;
}

int main()
{
    int tc;
    int n;
    int tmp;
    
    cin>>tc;
    for (int idx = 0; idx < tc; idx++)
    {
        int sum = 0;
        vector<int> lists;
        cin>>n;
        for (int i = 0; i < n; i++)
        {
            cin>>tmp;
            lists.push_back(tmp);
            
            
        }
        cout << get_total(lists)/2 << "\n";
        
    }
    
    return 0;
}
