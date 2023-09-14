#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MAX_N = 20;
const int MAX_M = 20;

int N, M;
char board[MAX_N][MAX_M];
int coin1_x, coin1_y, coin2_x, coin2_y;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

struct State {
    int coin1_x, coin1_y, coin2_x, coin2_y;
};

bool isValid(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < M;
}

int bfs() {
    bool visited[MAX_N][MAX_M][MAX_N][MAX_M];
    memset(visited, false, sizeof(visited));

    queue<pair<State, int> > q;
    State start = {coin1_x, coin1_y, coin2_x, coin2_y};
    q.push(make_pair(start, 0));
    visited[coin1_x][coin1_y][coin2_x][coin2_y] = true;

    while (!q.empty()) {
        State cur = q.front().first;
        int moves = q.front().second;
        q.pop();

        if (moves > 10) {
            return -1;
        }

        for (int dir = 0; dir < 4; dir++) {
            int next_coin1_x = cur.coin1_x + dx[dir];
            int next_coin1_y = cur.coin1_y + dy[dir];
            int next_coin2_x = cur.coin2_x + dx[dir];
            int next_coin2_y = cur.coin2_y + dy[dir];

            bool coin1_falls = !isValid(next_coin1_x, next_coin1_y);
            bool coin2_falls = !isValid(next_coin2_x, next_coin2_y);

            if (coin1_falls && coin2_falls) {
                continue; // 둘 다 떨어지면 무효
            }

            if (coin1_falls || coin2_falls) {
                return moves + 1; // 하나만 떨어지면 현재까지의 이동 횟수 반환
            }

            if (!visited[next_coin1_x][next_coin1_y][next_coin2_x][next_coin2_y]) {
                State next_state = {next_coin1_x, next_coin1_y, next_coin2_x, next_coin2_y};
                q.push(make_pair(next_state, moves + 1));
                visited[next_coin1_x][next_coin1_y][next_coin2_x][next_coin2_y] = true;
            }
        }
    }

    return -1; // 두 동전 모두 떨어지지 않는 경우
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'o') {
                if (coin1_x == 0) {
                    coin1_x = i;
                    coin1_y = j;
                } else {
                    coin2_x = i;
                    coin2_y = j;
                }
            }
        }
    }

    int result = bfs();
    cout << result << endl;

    return 0;
}
