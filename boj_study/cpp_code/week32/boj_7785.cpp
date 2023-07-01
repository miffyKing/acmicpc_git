#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
    int n;
    set <string> names;
    string input;
    string inout;
    vector <string> answer;
    cin>>n;
    for(int i = 0; i< n; i++)
    {
        cin>>input;
        cin>>inout;
        if(inout == "enter")
            names.insert(input);
        if(inout == "leave")
            names.erase(input);
    }
    for(auto i : names)
        answer.push_back(i);
    for(int i = names.size()-1; i>= 0; i--)
        cout<<answer[i]<<'\n';
    return 0;
}
