#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int n,a,b,c,d;
vector <pair<int,int>> input;
int monthes[13] = {0, 31,28,31,30,31,30,31,31,30,31,30,31};
int begin = 60;
int end = 334;

int get_days(int month, int days)
{
    int val = 0;
    for(int i = 1; i< month; i++)
        val += monthes[i];
    val += days;
    return val;
}       //몇월 몇일을 그냥 일수로 계산하여 리턴

int main()
{
    // 시작일 기준으로 정렬.
    cin>>n;
    for(int i = 0; i< n; i++)
    {
        cin>>a>>b>>c>>d;
        int start = get_days(a,b);
        int end = get_days(c,d);
        input.push_back(make_pair(start, end));
    }
    //시작일 기준으로 작은순으로 정렬함
    sort(input.begin(), input.end());
    
    int cnt = 0;
    int idx= -1;
    int temp = 0;
    int result =0;
    //시작지점 정하기..
    for (int i = 60; i <= 334 && idx < n; i = temp)
    {
        bool flag = false;
        idx++;
        for (int j = idx; j < n; j++)
        {
            if (input[j].first > i)
                break;
            if (temp < input[j].second)
            {
                temp = input[j].second;
                idx = j;
                flag = true;
            }
        }
        if (flag)
            result++;
        else
        {
            cout << 0 << "\n";
            return 0;
        }
    }
    cout << result << "\n";
    return 0;
}
