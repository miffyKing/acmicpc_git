#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int main()
{
    //증가하는 순으로 스택에 계속 집어넣고
    //감소하는 순간 스택에서 다 빼서 그 차익만을 ans 에 ++ 한다
    //다시 차근차근 넣는다.
    int stock_value[1000000];
    int test_num,day_num;
    long long profit_sum=0;
     int max_stock=0;
    int n;
    cin>>n;
    for(int i =0; i<n ; ++i)
    {
        cin>>day_num;
        for(int day=0; day< day_num; ++day)
          cin>>stock_value[day];
        
        profit_sum=0;
        max_stock=0;
        for(int day=day_num -1 ; day>=0 ; --day){
          if(stock_value[day] < max_stock)
            profit_sum += (max_stock - stock_value[day]);
          else
            max_stock = stock_value[day];
        }
        cout<<profit_sum<<'\n';
    }
    return 0;
}
