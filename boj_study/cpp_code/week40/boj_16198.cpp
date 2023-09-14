#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> W(N);
    for (int i = 0; i < N; i++) {
        cin >> W[i];
    }

    vector<vector<int> > dp(N, vector<int>(N, 0));

    // 에너지 구슬을 하나씩 선택하면서 최대 에너지를 구함
    for (int len = 2; len < N; len++) {
        for (int i = 0; i < N - len; i++) {
            int j = i + len;
            dp[i][j] = 0;
            for (int k = i + 1; k < j; k++) {
                dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + W[i] * W[j]);
            }
        }
    }

    cout << dp[0][N - 1] << endl;
    
    return 0;
}
