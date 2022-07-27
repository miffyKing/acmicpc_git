#include <iostream>
#include <cstring>
#include <string.h>
#include <string>
#include <cmath>
#include <vector>
#include <numbers>
#include <math.h>
#include <algorithm>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <tuple>
#include <utility>
#include <typeinfo>
#include <iomanip>
#include <set>
#include <map>

using namespace std;

int mushroom[150001];
int dp[150001][2];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> mushroom[i];
    }
    
    dp[0][0] = 0;
    dp[0][1] = -1;

    for (int i = 0; i < n; i++) {

        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + mushroom[i]);
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - mushroom[i]);
    }
    cout << max(dp[n - 1][0], dp[n - 1][1]);
}
