#include <iostream>
#include <vector>
#include <math.h>
#include <set>

using namespace std;

pair<int,int> yakboon(int ori_i, int ori_j)
{
    int i, j;
    i = ori_i;
    j = ori_j;
    int divisor = 2;
    int answer = 1;
    while (divisor <= i || divisor <= j)
    {
        if (i%divisor != 0 || j%divisor != 0)
        {
            divisor++;
        }
        else{
            i/=divisor;
            j/=divisor;
            answer *= divisor;
        }
    }
//    cout<< ori_i/answer << " " << ori_j/answer <<"\n";
    return make_pair(ori_i/answer, ori_j/answer);
    
}

int main()
{
    set<pair<int,int>> seats;
    int d1,d2;
    
    //d1 부터 d2 까지 돌면서(n) 360을 n 으로 나눈 각 5개가 나오겠지(0 부터 ..0+n , 0+n+n..)
    //소수로 넣으면 못찾아서 그런가보다 -> map 에 분모 분자를 담아보자 (1/r, 2/r .. 이거로 하자)
    cin>>d1>>d2;
    
    for (int i = d1; i <= d2; i++)
    {
        for (int j = 1; j < i; j++)
        {
//            cout<<"i   : " << i << " J    :  " << j << "\n";
            pair<int,int> result = yakboon(i, j);
            if( seats.find(result) == seats.end())
            {
                
                seats.insert(result);
            }
        }
    }
    
//    for (auto iter : seats)
//    {
//        cout<<iter.first << " " << iter.second <<"\n";
//    }
    cout<<seats.size() + 1<<"\n";
    return 0;
}
