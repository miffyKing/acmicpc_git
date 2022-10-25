#include<iostream>
#include<string>
#include <map>
#include<set>
#include<stack>
#include <vector>
#include <functional>
#include <algorithm>
#include<cmath>
#include <cstring>
#include <set>
#include <stdio.h>
//#include <string.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,m;
    cin>>n>>m;
    
    cout<<n/2+m/2<<'\n';
    
    for (int i = n % 2; i < n; i += 2)
        cout << i + 1 << " 1 " << i + 1 << " " << m << "\n";
    for (int i = m % 2; i < m; i += 2)
        cout << "1 " << i + 1 << " " << n << " " << i + 1 << "\n";


}
