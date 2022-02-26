#include<iostream>
#include<string>
#include <map>
#include<set>
#include<stack>
#include<queue>
#include <vector>
#include <functional>
#include <algorithm>
#include<cmath>
#include <cstring>
#include <set>
#include <stdio.h>
//#include <string.h>
using namespace std;

int price[10];

int main() {
    
    ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
    
    int N; cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> price[i];
    int money; cin >> money;

    int a = N - 1;
    for (int i = N - 2; i > 0; --i) if (price[i] < price[a])
        a = i;
    if (a == 0 || money < price[a]) { cout << 0; return 0; }
    int b = (price[0] < price[a] ? 0 : a);

    vector<int> ans;
    ans.emplace_back(a);
    money -= price[a];
    while (money >= price[b]) {
        ans.emplace_back(b);
        money -= price[b];
    }

    for (int i = 0; money && i < ans.size(); ++i) {
        int cur = ans[i];
        for (int nxt = N - 1; nxt > cur; --nxt)
            if (money >= price[nxt] - price[cur]) {
                money -= price[nxt] - price[cur];
                ans[i] = nxt;
                break;
            }
    }
    for (int x : ans) cout << x;
    return 0;
}

