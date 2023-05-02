#include <iostream>
#include <stack>
using namespace std;
stack<int> s[8];
int main(){
    int n, p;
    cin >> n >> p;
    
    int a,b;
    int ans = 0;
    for (int i = 0; i < n; i++){
        cin >> a >> b;
        if(s[a].empty()){ // 아무것도 누르지 않고 있을 때
            s[a].push(b); // 눌러줌
            ans++; // 움직임 추가
        }
        else if(s[a].top() < b){ // 누르고 있는 음보다 높은 것을 누를때
            s[a].push(b); // 눌러줌
            ans++; // 움직임 추가
        }else if(s[a].top() > b){ 
            // 치고 싶은 음이 누르고 있는 음보다 작을때
            while(s[a].top()>b){
                s[a].pop(); // 음이 나올때 까지 손을 때 줌.
                ans++; // 움직임 추가
                if(s[a].empty()){ 
                // 누르고 있는 음 전부가 치고 싶은 음보다 낮을 때
                    s[a].push(b); // 전부 손을 떼고 눌러줌
                    ans++; // 움직임 추가
                }
            }
            if(s[a].top() < b){ 
            //손을 떼다 누루고 있는 음이 치고 싶은 음 보다 더 작을때
                s[a].push(b); // 눌러줌
                ans++; // 움직임 추가
            } 
            // 손을 떼다 누르고 있는 음이 치고있는 음과 같을 때는 움직임 추가가 없어도됨.
        }
    }
    cout << ans;
    return 0;
}