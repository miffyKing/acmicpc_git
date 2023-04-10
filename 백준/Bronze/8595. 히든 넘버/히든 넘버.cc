#include <iostream>
#include <string>

using namespace std;

int main() {
    string input;
    long long sum = 0;
    int n;
    cin>>n;
    cin>>input;
    int i = 0;
    while (i < input.length()) {
        if (isdigit(input[i])) {
            string numStr;
            while (i < input.length() && isdigit(input[i])) {
                numStr += input[i];
                i++;
            }
            sum += stoi(numStr);
        }
        else {
            i++;
        }
    }
    cout << sum << endl;
    return 0;
}
