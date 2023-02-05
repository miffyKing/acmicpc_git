#include <iostream>
#include <math.h>
#include <vector>
#include <map>
#include <set>


using namespace std;

bool visited[1000001];
vector <int> prime_list;
set<int> prime_pack;

void get_prime(int n)
{
    for (int i = 0; i < prime_list.size(); i++)
    {
        if (prime_pack.find(n - prime_list[i]) != prime_pack.end())
        {
            cout<<n << " = " << prime_list[i] << " + " << n - prime_list[i] << "\n";
            break;
        }
    }

}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    for(int i = 2; i <=1000000; i++ ) visited[i] = true;

    for (int i = 2; i <= 1000; i++)
    {

        if (visited[i] == true)
        {
            //prime_list.push_back(i);
            for(int j = i*2; j <= 1000000; j+=i)
            {
                visited[j] = false;
            }
        }
    }
    for (int i = 2; i <= 1000000; i++)
    {
        if (visited[i] == true){
            prime_list.push_back(i);
            if (i % 2 == 1)
            {
                prime_pack.insert(i);
            }
            
        }
    }

    int n;
    while(1)
    {
        cin>>n;
        if (n == 0)
            break;
        get_prime(n);
    }
    return (0);
}
