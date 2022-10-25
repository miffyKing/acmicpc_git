#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    string input;
    int z_cnt = 0;
    int o_cnt = 0;
    cin>>input;
    if(input[0] == '0')
        z_cnt++;
    else
        o_cnt++;
    for(int i =1; i< input.size(); i++)
    {
        if(input[i] != input[i-1])
        {
            if(input[i] == '0')
                z_cnt++;
            else
                o_cnt++;
        }
    }
    cout<<min(z_cnt, o_cnt);
    return 0;
}
