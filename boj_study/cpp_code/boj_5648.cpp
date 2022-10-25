#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int num;
    cin >> num;
    vector<long long> ans;
    for (int i = 0; i < num; i++){
        string tmp;
        cin >> tmp;
        reverse(tmp.begin(), tmp.end());
        ans.push_back(stoll(tmp));
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < num; i++)
        cout << ans[i] << '\n';
    return (0);
}
