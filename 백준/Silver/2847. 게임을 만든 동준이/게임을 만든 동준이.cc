#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n,tmp;
    vector<int> list;
    long long answer = 0;
    cin>>n;
    for(int i = 0; i< n ;i++)
    {
        cin>>tmp;
        list.push_back(tmp);
    }
   
    for(int i = n-1; i>=1 ; i--)
    {
        if (list[i] <= list[i-1])
        {
            answer = answer + (list[i-1] - (list[i] -1));
            list[i-1] = list[i] -1;
        }
    }
    cout<<answer<<'\n';
    
    return 0;
}
