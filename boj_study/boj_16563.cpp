
#include <iostream>
#include <vector>

using namespace std;

int minfactor[5000001];

vector<int> get_soinsoo(int tmp, vector<int> list)
{
    vector<int> result;
    while(tmp > 1)
    {
        result.push_back(minfactor[tmp]);
        tmp /= minfactor[tmp];
    }
    return result;
}



int main()
{
    int n;
    //vector<int> arr;
    vector<int> sosu_list;
    
    
    for (int i = 2; i <= 5000000; i++)
    {
        minfactor[i] = i;
    }
    for (int i =2 ; i*i <= 5000000; i++)
    {
        if (minfactor[i] == i)
        {
            for (int j = i*i; j <= 5000000; j+=i)
            {
                if (minfactor[j] == j)
                    minfactor[j] = i;
            }
        }
    }
    for (int i = 2; i <= 5000000; i++)
    {
        if (minfactor[i] == i)
            sosu_list.push_back(i);
    }

    cin>>n;
    
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin>>tmp;
        vector<int> ans = get_soinsoo(tmp, sosu_list);
        for (int j = 0; j < ans.size(); j++)
        {
            cout<< ans[j] << ' ';
        }
        cout<<'\n';
    }
    return 0;
}


