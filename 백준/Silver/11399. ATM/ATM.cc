#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    //일단 다 입력받고, 정렬한다.
    int n,tmp;
    vector <int> time;
    
    cin>>n;
    for(int i = 0; i<n;i++)
    {
        cin>>tmp;
        time.push_back(tmp);
    }
    sort(time.begin(), time.end());
    long long ans =0;
    for(int i = 0; i< n; i++)
        ans = ans + time[i] * (n-i);
    cout<<ans<<'\n';
    return 0;
}
