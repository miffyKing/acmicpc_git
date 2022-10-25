#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main()
{
    //디큐에 1부터 그냥차례대로 집어넣고
    //pop_front, push_back 연산,
    //pop_back, push_front 연산을 하면서 인덱스들을 왔다리갔다리 시킨다.
    deque <int> dq;
    int n, m;
    cin>>n>>m;
    for(int i = 1; i<= n; i++)
        dq.push_back(i);
    int cnt = 0;
    for(int k = 0; k< m ;k++)
    {
        int tmp, position;
        cin>>tmp;
        for(int i = 0; i < dq.size(); i++)
        {
            if (dq[i] == tmp)
            {
                position = i;
                continue;
            }
        }
        if (position == 0)  //그냥 pop만,
        {
            dq.pop_front();
            continue;
        }
        if (position > (dq.size()/2)) //dq 전체에서 좀 오른쪽에 있는경우 (3번이 이득)
        {
            int idx = 0;
            while(idx < dq.size())
            {
                if (dq.front() == tmp)
                {
                    dq.pop_front();
                    break;
                }
                int num = dq.back();
                dq.pop_back();
                dq.push_front(num);
                cnt++;
                idx++;
            }
        }
        else if (position <= (dq.size()/2)) //dq 전체에서 좀 왼쪽에 있는경우 (2번이 이득)
        {
            int idx = 0;
            while(idx < dq.size())
            {
                if (dq.front() == tmp)
                {
                    dq.pop_front();
                    break;
                }
                int num = dq.front();
                dq.pop_front();
                dq.push_back(num);
                cnt++;
                idx++;
            }
        }
    }
    cout<< cnt<<'\n';
}
