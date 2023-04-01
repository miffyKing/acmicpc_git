#include <iostream>
 
using namespace std;
 
int main(int argc, char const *argv[]) {
    int N, X;
    cin >> N >> X;
 
    int arr[10000];    // 최대 가질 수 있는 N은 10000이므로, 10000칸의 배열 생성
 
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
 
    // i번째 원소가 X보다 작으면 출력
    for (int i = 0; i < N; i++) {
        if (arr[i] < X) {
            cout << arr[i] << " ";    // 출력 형식 주의 (원소간 공백이 있음)
        }
    }
    return 0;
}
