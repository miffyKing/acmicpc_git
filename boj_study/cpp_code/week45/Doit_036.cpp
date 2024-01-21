#include <iostream>
#include <vector>

using namespace std;

int getMaxDistance(vector<vector<int> >& A, int N, int M, int currentHeight, int numHeightChanges) {
    if(numHeightChanges == 0) {
        int distance = 0;
        bool crashed = false;

        for(int i = 0; i < N; i++) {
            if(A[i][currentHeight-1] == 1) {
                crashed = true;
                break;
            }

            distance++;
        }

        return (crashed) ? 0 : distance;
    }

    int maxDistance = 0;

    for(int newHeight = 1; newHeight <= M; newHeight++) {
        if(newHeight != currentHeight) {
            vector<vector<int> > newA = A;

            int distance = 0;
            bool crashed = false;

            for(int i = 0; i < N; i++) {
                if(A[i][newHeight-1] == 1) {
                    crashed = true;
                    break;
                }

                distance++;
            }

            if(!crashed) {
                for(int i = 0; i < N; i++) {
                    newA[i][newHeight-1] = 0;
                }

                int remainingDistance = getMaxDistance(newA, N, M, newHeight, numHeightChanges - 1);
                maxDistance = max(maxDistance, distance + remainingDistance);
            }
        }
    }

    return maxDistance;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int> > A(N, vector<int>(M));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> A[i][j];
        }
    }

    int numHeightChanges;
    cin >> numHeightChanges;

    int maxDistance = 0;

    for(int height = 1; height <= M; height++) {
        maxDistance = max(maxDistance, getMaxDistance(A, N, M, height, numHeightChanges));
    }

    cout << maxDistance << endl;

    return 0;
}
