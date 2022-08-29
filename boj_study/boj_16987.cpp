
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxval = -1;
int n;
int isused[9];
vector <pair<int, int>> eggs;

void bt_func(int idx)
{
    if (idx == eggs.size())
    {
        int cnt = 0;
        for(int i =0; i< n; i++)
        {
            if (eggs[i].first <= 0)
                cnt++;
        }
        if (cnt >= maxval)
            maxval = cnt;
        return;
    }
    bool crashflag = false;
    if (eggs[idx].first <= 0) bt_func(idx + 1);
    else
    {
        for (int i = 0; i< n; i++)
        {
            if (eggs[i].first <= 0 || i == idx) continue;
            eggs[idx].first -= eggs[i].second;
            eggs[i].first -= eggs[idx].second;
            crashflag = true;
            bt_func(idx+1);
            eggs[idx].first += eggs[i].second;
            eggs[i].first += eggs[idx].second;
        }
    }
    if (!crashflag )bt_func(n);
}
int main()
{
    cin>>n;
    int tmp1, tmp2;
    for (int i =0; i<n; i++)
    {
        cin>>tmp1>>tmp2;
        eggs.push_back(make_pair(tmp1, tmp2));
    }
    bt_func(0);
    //일단 입력을 받을 때 vector<pair> 로 입력을 받고, isused 배열도 만들자.
    //백트래킹인데 몇번째까지 해야한다는 그건 없고,
    //이미 지나친 계란은 다시 집어들수 없다는거가 있음.
    // 쳐서 피가 까이는 거 계속 벡터에서 반영해주면서, isused 체크 해주어야함.
    //만약 계란이 쳐서 박살이 났다면?(isused 체크하고, 개수 증가시켜주자.)
    //종료조건? 지금 잡고 있는 애의 idx 가 벡터의 사이즈일때!
    cout<<maxval<<'\n';
    return 0;
}
