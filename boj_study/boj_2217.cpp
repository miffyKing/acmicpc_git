#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int n;
    vector<int> arr;
    cin>>n;
    int tmp2;
    for(int i = 0; i< n; i++){
        cin>>tmp2;
        arr.push_back(tmp2);
    }
    sort(arr.begin(), arr.end(), greater<>());
    long long max_w = 0;
    for(int i = 0; i < n; i++)
    {
        long long tmp = arr[i] * (i+1);
        if (max_w < tmp)
            max_w = tmp;
    }
    cout<<max_w<<'\n';
    return 0;
}
