#include <iostream>
#include <vector>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <set>

using namespace std;

//vector<bool> visited(1000002, true);
int visited[1000002];
vector<int> prime_list;

bool check_gongik(int n)    //상근인지 체크
{
    set<int> num_pack;
    
    string n_to_str = to_string(n);
    num_pack.insert(n);

    while (1)
    {
        int sum = 0;
        for (int i = 0; i < n_to_str.size(); i++)
        {
            sum += (n_to_str[i] - '0') *(n_to_str[i] - '0');
        }
        if (num_pack.find(sum) == num_pack.end())   //이 경우가 지금 set에 없다는 뜻
        {
            num_pack.insert(sum);
            n_to_str = to_string(sum);
        }
        else
        {
            return false;
        }
        if (sum == 1)
            return true;
    }
    return true;
}

int main()
{
    string n;
    cin>>n;
    // 소수리스트 부터 에라토스로 만들고
    // 그 수들을 하나씩 상근수인지 확인한다.
        // 계속 만들어가면서 set에 계속 갈기면서 이미 set에 존재한 값이었다면 반복이 있다고 판단하고 상근수가 아니라고 판단하자.
    
    for (int i = 0; i <= 1000000; i++)
    {
        visited[i] = true;
    }
    
    for (int i = 2; i <= 1000; i++)
    {
        for (int j = 2 * i; j <= 1000000; j+=i)
            visited[j] = false;
    }
    for (int i = 2; i<= 1000000; i++)
    {
        if (visited[i] == true)
            prime_list.push_back(i);
    }
    
    int i = 0;
    vector<int> answer_list;
    while(i < prime_list.size() && prime_list[i] <= atoi(n.c_str()))      // string 타입인 n을 c_str 로 char * 로 바꿔서 atoi를 갈겨요.
    {
      //  cout<<"number is " << prime_list[i] << "\n";
        if ( check_gongik(prime_list[i]) == true)
            answer_list.push_back(prime_list[i]);
        i++;
    }
    
    for (int i = 0; i < answer_list.size(); i++)
    {
        cout<<answer_list[i] << "\n";
    }
    return 0;
}
        
