#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

bool compareString(int a, int b)
{
    string aStr = to_string(a);
    string bStr = to_string(b);
    return aStr+bStr > bStr+aStr;
}

string solution(vector<int> numbers) {
    string answer = "";
    int zero_flag = 0;
    for (int i = 0; i < numbers.size(); i++)
    {
        if (numbers[i] != 0)
        {
            zero_flag = 1;
            break;
        }
    }
    if (zero_flag == 0)
    {
        return "0";
    }
    sort(numbers.begin(), numbers.end(), compareString);
    
    for(int i = 0; i< numbers.size(); i++)
    {
        answer += to_string(numbers[i]);
    }
    
    return answer;
}