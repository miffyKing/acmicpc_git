#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;
#define ffor(i, x) for (int (i) = 0; (i) < (x) ; (i)++) // :별:️ 0부터 x까지 for-loop
#define cc(x) cin >> (x); // :별:️ stdin 인풋 하나 받기
int  is_operator(int op) {
    return (op == '+' || op == '-' || op == '*' || op == '/');
}
int precedence(int op) {
    if (op == '(') return 0;
    else if (op == '+' || op == '-') return 1;
    else if (op == '*' || op == '/') return 2;
    else return 3;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string input;
    cc(input);
    stack <char> s;
    vector <char> v;
    int i = 0;
    while (input[i]){
        if (input[i] == '(')
            s.push(input[i++]);
        else if (input[i] == ')'){
            while (s.top() != '(') {
                v.push_back(s.top());
                s.pop();
            }
            s.pop();
            i++;
        }
        else if (is_operator(input[i])) {
            while (!s.empty()
                && precedence(s.top()) >= precedence(input[i])){
                v.push_back(s.top());
                s.pop();
            }
            s.push(input[i++]);
        }
        else if (input[i] >= 'A' && input[i] <= 'Z')
            while (input[i] >= 'A' && input[i] <= 'Z')
                v.push_back(input[i++]);
    }
    while (!s.empty()) {
        v.push_back(s.top());
        s.pop();
    }
    ffor(i, v[i])
        cout << v[i];
    return (0);
}
