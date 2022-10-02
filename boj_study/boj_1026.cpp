#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    vector<int> A;
    vector<int> B;
    int tmp;
    cin>>n;
    for(int i = 0; i< n; i++)
    {
        cin>>tmp;
        A.push_back(tmp);
    }
    for(int i = 0; i< n; i++)
    {
        cin>>tmp;
        B.push_back(tmp);
    }
    sort(A.begin(), A.end(), greater<>());
    sort(B.begin(), B.end());
    long long ans = 0;
    for(int i =0; i< n; i++)
    {
        ans = ans + (A[i]*B[i]);
    }
    cout<<ans<<'\n';
    return 0;
}
