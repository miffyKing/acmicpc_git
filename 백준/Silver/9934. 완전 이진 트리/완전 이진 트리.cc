#include <iostream>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

vector<int> lst;
vector<int> flor[12];

int total_n;
int n;

void dp_func(int from, int to, int level)
{
    if(from == to)
    {
        return;
    }
    int mid = (from + to)/2;
    
    flor[level].push_back(lst[mid]);
    dp_func(from, mid, level + 1);
    dp_func(mid+1, to, level + 1);
}

int main()
{
    int tmp;
    cin>>n;
    total_n = pow(2,n);
    for (int i = 0; i < pow(2,n) -1 ; i++)
    {
        cin>>tmp;
        lst.push_back(tmp);

    }

    dp_func(0, total_n -1, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < flor[i].size(); j++)
        {
            cout<< flor[i][j] << " ";
        }
        cout<<"\n";
    }


    return 0;
}