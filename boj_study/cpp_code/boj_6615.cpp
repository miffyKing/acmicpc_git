#include <iostream>
#include <vector>
#include <set>

using namespace std;


int main()
{
    int a, b;
    while(1)
    {
        cin>>a >>b;
        if (a == 0 && b == 0)
        {
            break;
        }
        set<pair<int,int>> a_lst;
        vector<int> b_lst;

        int cnt = 0;
        while(a != 1)
        {

            if (a % 2 == 0)
            {
                a_lst.push_back({a, cnt});
                a/=2;
            } else
            {
                a_lst.push_back({a, cnt});
                a= a*3 + 1;
            }
            cnt++;
        }

        cnt = 0;
        while (b != 1)
        {
            if (a_lst.find(b) != a_lst.end())
            {
                
            }
            if (b % 2 == 0)
            {
                b_lst.push_back(b);
                b/=2;
            } else
            {
                b_lst.push_back(b);
                b = b*3 + 1;
            }
            cnt++;
        }
        
        vector<pair<int,int>> ans_lst;


    }

    //7 22 11 34 17 52 26 13 40 20 10 5 16 8
    //8 이렇게,
    return 0;
}