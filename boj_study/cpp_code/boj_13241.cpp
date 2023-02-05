#include <iostream>
#include <vector>

using namespace std;

int main()
{
    long long int A, B;

    cin>>A >> B;
    for (int i = 1; i<= A*B; i++)
    {
        if (A*i % B == 0)
        {
            cout<<A*i<<"\n";
            break;
        }
    }
    return 0;
}