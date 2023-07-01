#include <stdio.h>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

string arr;
vector<int> jarisoo;


int main() {

    int N, K;
    scanf("%d %d", &N, &K);

    long long n, idx = 0;
    while ((n = 9*(long long)pow(10, idx)*(idx+1)) <= K) {
        K-=n;
        idx++;
    }
    long long num = (long long)pow(10, idx)+(K+idx)/(idx+1)-1;
    if (num > N) printf("-1");
    else printf("%c",to_string(num)[(K+idx)%(idx+1)]);
    return 0;
}

// 1 2 3 4 5 6 7 8 9 1 
// 0 1 1 1 2 1 3 1 4 1 
// 5 1 6 1 7 1 8 1 9 2  0 2 1