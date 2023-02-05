#include <iostream>
#include <vector>
#include <math.h>


using namespace std;

int main()
{
    long a_jinbub;
    long b_jinbub;
    int m;
    vector<int> a_list;

    cin>>a_jinbub >> b_jinbub;
    cin>>m;
    for (int i = 0; i < m ; i++)
    {
        int tmp;
        cin>>tmp;
        a_list.push_back(tmp);
    }

    //10진수로 바꾸고
    long sum = 0;
    long idx;
    for (int i = 0; i < m; i++)
    {
        
        idx = pow(a_jinbub, m - i- 1);
        sum += (idx * a_list[i]);
    }
    //다시 B진수로 바꾼다.   
    vector<int> changed_b;
    while(sum != 0)
    {
        int namoji = (int)((int)sum % (int)b_jinbub);
          
        changed_b.push_back(namoji);
        sum /= b_jinbub;
    }
    for(int i = changed_b.size() -1; i >= 0; i--)
    {
        cout<< changed_b[i] << " ";
    }
    cout<<"\n";
}