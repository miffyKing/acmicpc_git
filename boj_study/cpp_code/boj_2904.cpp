#include <iostream>
#include <vector>
#include <map>

using namespace std;


bool visited[1000002]; //전역변수 선언 해야 true로로

int main()
{
    int n;
    vector<int> lst;
    
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin>>tmp;
        lst.push_back(tmp);
    }
   
    for (int i = 2; i <= 1000000; i++)
    {
        visited[i] = true;
    }

    vector<int> sosu_list;
    
    for (int i = 2; i*i <= 1000000; i++)
    {
        if (visited[i] == true)
        {
            sosu_list.push_back(i);
        }
        for (int j = 2*i; j <= 1000000; j+=i)
        {
            visited[j] = false;
        }
    }
    // 소수 구함.
    // 입력으로 받은 수들에 대해 소인수 분해를 하고,
    // map 을 만들어서 2가 몇개, 3이 몇개 포함되어있는지 세어준다.
    // 이제 그 각각 개수를 n 으로 나눠서 gcd 를 구한다.
    
    map<int, int> total_sosu; // 전체 소수가 2가 몇개, 3이 몇개 있는지 저장
    map<int,int> each_soinsoo[102];     // 각자 숫자들의 소인수들을 저장함.

    for (int i = 0; i < lst.size(); i++)
    {
        int chunk = lst[i];
        for (int j = 0; j < sosu_list.size(); j++)
        {
            if (chunk == 1) break;
            int cnt = 0;
            while (chunk % sosu_list[j] == 0)
            {
                chunk/= sosu_list[j];
                total_sosu[sosu_list[j]]++;     // 전체 소수가 각각 몇개있는지를 저장했습니다.
                each_soinsoo[i][sosu_list[j]]++;
                 // 이제, 각각 숫자의 소인수 분해를 저장하고 있는 맵을 만들거에욤. map 배열을 만들어서 순서대로 저장해보면 될듯
            }
        }
    }

    int gcd = 1;
    map<int, int> gcd_component;
    for (auto iter : total_sosu)
    {
        int divided = iter.first * ( iter.second / n);
        // 이값이 0이면 그냥 안곱해 주면 되겠죠 -> 서로소 인 애들일 수 있으니깐
        if (divided != 0)
        {
            gcd_component[iter.first]+=iter.second / n;
            gcd *= divided;
        }
    }

    // 이제 구한 소인수랑 각각의 값을 비교하면서 ..

    int total_calculate = 0;
    for (int i = 0; i < n ; i++)
    {
        for (auto iter : gcd_component)
        {
            int search_sosu = iter.first;

            int soinsoo_cnt_n;
            if (each_soinsoo[i].find(search_sosu) == each_soinsoo[i].end())
            {
                soinsoo_cnt_n = 0;      //존재하지 않는 소수라서 못찾았을 때.
            } else{
                soinsoo_cnt_n = each_soinsoo[i].find(search_sosu)->second;    
            }
             
            int gcd_cnt = gcd_component.find(search_sosu)->second;
       
            if (soinsoo_cnt_n < gcd_cnt) //만약 현재 보고있느 수의 소수2 개수가 gcd 의 소수2 개수보다 작다면, 그 개수만큼 어딘가에서 가져와야함.
            {
                total_calculate+= (gcd_cnt - soinsoo_cnt_n);
            }
        }
    }

    cout<<gcd << " " <<  total_calculate<<"\n";    
}