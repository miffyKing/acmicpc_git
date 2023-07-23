#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    cin.ignore(); // Consume the newline character after reading n.

    int s = 0; // 비트마스크로 집합 표현

    while (n--)
    {
        string line;
        getline(cin, line);

        int space_pos = line.find(' ');
        string order = line.substr(0, space_pos);

        if (order == "add")
        {
            int num = stoi(line.substr(space_pos + 1));
            s |= (1 << num); // 해당 원소를 추가하는 비트마스크 연산
        }
        else if (order == "remove")
        {
            int num = stoi(line.substr(space_pos + 1));
            s &= ~(1 << num); // 해당 원소를 제거하는 비트마스크 연산
        }
        else if (order == "check")
        {
            int num = stoi(line.substr(space_pos + 1));
            cout << ((s & (1 << num)) ? 1 : 0) << "\n"; // 해당 원소가 있는지 확인하는 비트마스크 연산
        }
        else if (order == "toggle")
        {
            int num = stoi(line.substr(space_pos + 1));
            s ^= (1 << num); // 해당 원소의 포함 여부를 반전시키는 비트마스크 연산
        }
        else if (order == "all")
        {
            s = (1 << 21) - 1; // 모든 원소를 포함하는 비트마스크 연산
        }
        else if (order == "empty")
        {
            s = 0; // 모든 원소를 제거하는 비트마스크 연산
        }
    }

    return 0;
}
