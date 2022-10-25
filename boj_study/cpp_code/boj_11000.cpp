#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int,int>> times;

int main()
{
    int n;
    int tmp1,tmp2;
    cin>>n;
    for(int i = 0; i< n ;i++)
    {
        cin>>tmp1>>tmp2;
        times.push_back(make_pair(tmp1, tmp2));
    }
    return 0;
}
